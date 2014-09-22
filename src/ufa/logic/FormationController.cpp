#include "ufa/logic/FormationController.hpp"
#include "ufa/general/Math.hpp"
#include "ufa/general/Logging.hpp"

#define POSITION_EPS 0.001f
#define FORMATION_POSITION_EPS 0.01f

namespace ufa
{

	FormationController::FormationController(const std::vector<std::shared_ptr<Unit>> &p_units,
											 FormationShape *p_formationShape)
	:formationShape_(p_formationShape)
	{
		formation_.units.reserve(p_units.size());
		for(int i = 0; i < p_units.size(); ++i) {
			formation_.units.push_back(FormationUnit());
			formation_.units.back().unit = p_units[i];
		}
		
		formationShape_->calcFormationPositions(formation_);
		selectCommander();
	}
	
	void FormationController::selectCommander()
	{
		formation_.commander.position.set(0,100);
		for(int i = 0; i < formation_.units.size(); ++i) {
			if(formation_.units[i].position.x > formation_.commander.position.x) {
				// unit is nearer at front position
				formation_.commander = formation_.units[i];
			} else if(sameFloat(formation_.units[i].position.x, formation_.commander.position.x, FORMATION_POSITION_EPS)) {
				// unit is in same row
				if(fabs(formation_.units[i].position.y) < fabs(formation_.commander.position.x)) {
					// unit is nearer to mid
					formation_.commander = formation_.units[i];
				}
			}
		}
	}

	FormationController::~FormationController()
	{
	}
	
	Formation& FormationController::getFormation()
	{
		return formation_;
	}
	
	void FormationController::moveTo(const Vec2& p_targetPosition)
	{
		if(formation_.state != FORMED)
			formUpAt(p_targetPosition);
		else {
			formation_.targetPosition = p_targetPosition;
			formation_.moving = true;
			updateFormationOrientation();
		}
	}
	
	void FormationController::formUpAt(const Vec2 &p_position)
	{
		formation_.center = p_position;
		setUnitTargetPositions();
		formation_.state = FORMING;
	}
	
	void FormationController::setUnitTargetPositions()
	{
		for(int i = 0; i < formation_.units.size(); ++i) {
			Vec2 targetPosition = formation_.center + rotateVector(formation_.units[i].position, formation_.orientation);
			formation_.units[i].unit->moveToTarget(targetPosition);
		}
	}
		
	void FormationController::step(const unsigned int p_usec)
	{
		switch(formation_.state) {
			case BROKEN:
				return;
			case FORMING:
				formFormation(p_usec);
			case FORMED:
				moveFormation(p_usec);
			default:
				return;
		}
	}
	
	void FormationController::formFormation(const unsigned int p_usec)
	{
		if(hasFormedUp()) {
			formation_.state = FORMED;
			PRINT_INFO("Formation formed.");
		}
	}
	
	bool FormationController::hasFormedUp()
	{
		for(int i = 0; i < formation_.units.size(); ++i) {
			if(!formation_.units[i].unit->reachedTarget(POSITION_EPS))
				return false;
		}
		
		return true;
	}
	
	void FormationController::moveFormation(const unsigned int p_usec)
	{
		if(formation_.moving) {
			updateFormationCenter(formation_.commander.unit->position);
			setUnitTargetPositions();
			
			calcCommanderVelocity(p_usec);
			
			Vec2 commanderFuturePos = formation_.commander.unit->position + formation_.commander.unit->velocity * usecToSec(p_usec);
			updateFormationCenter(commanderFuturePos);
			setUnitTargetPositions();
		}
	}
	
	void FormationController::updateFormationOrientation()
	{
		Vec2 diff = formation_.targetPosition - formation_.center;
		formation_.orientation = atan2(diff.y, diff.x);
	}
	
	void FormationController::updateFormationCenter(const Vec2 &p_commanderPosition)
	{
		formation_.center = p_commanderPosition - rotateVector(formation_.commander.position, formation_.orientation);
	}
	
	void FormationController::calcCommanderVelocity(const unsigned int p_usec)
	{
		float maxDistanceToTarget = 0;
		float minMaxVelocity = -1;
		int unit = -1;
		for(int i = 0; i < formation_.units.size(); ++i) {
			// get max distance to unit's target
			float distance = (formation_.units[i].unit->position - formation_.units[i].unit->targetPosition).lengthSQ();
			if(distance > maxDistanceToTarget) {
				maxDistanceToTarget = distance;
				unit = i;
			}
			
			// get min maxVelocity of all units
			if(minMaxVelocity > formation_.units[i].unit->maxVelocity || minMaxVelocity < 0)
				minMaxVelocity = formation_.units[i].unit->maxVelocity;
		}
		
		float toMove = usecToSec(p_usec) * formation_.units[unit].unit->maxVelocity;
		float diffMovement = toMove - sqrt(maxDistanceToTarget);
		if(diffMovement < 0)
			diffMovement = 0;
			
		diffMovement = diffMovement / usecToSec(p_usec);
		Vec2 formationDiff = formation_.targetPosition - formation_.center;
		float targetVelocity = MIN(MIN(diffMovement, minMaxVelocity), formationDiff.length());
		formation_.commander.unit->velocity.x = cos(formation_.orientation) * MIN(diffMovement, minMaxVelocity);
		formation_.commander.unit->velocity.y = sin(formation_.orientation) * MIN(diffMovement, minMaxVelocity);
	}
	
}
