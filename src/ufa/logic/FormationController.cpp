#include "ufa/logic/FormationController.hpp"
#include "ufa/general/Math.hpp"

namespace ufa
{

	FormationController::FormationController(const std::vector<std::shared_ptr<Unit>> &p_units,
											 FormationShape *p_formationShape,
											 FormationPlacement *p_formationPlacement)
	:formationShape_(p_formationShape), formationPlacement_(p_formationPlacement)
	{
		formation_.units.reserve(p_units.size());
		for(int i = 0; i < p_units.size(); ++i) {
			formation_.units.push_back(FormationUnit());
			formation_.units.back().unit = p_units[i];
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
		formation_.targetPosition = p_targetPosition;
		formation_.moving = true;
	}
	
	void FormationController::formUpAt(const Vec2 &p_position)
	{
		formation_.center = p_position;
		formationShape_->calcFormationPositions(formation_);
		formationPlacement_->placeUnits(formation_);
		setUnitTargetPositions();
		formation_.state = FORMING;
	}
	
	void FormationController::setUnitTargetPositions()
	{
		for(int i = 0; i < formation_.units.size(); ++i) {
			formation_.units[i].unit->targetPosition = formation_.center;
			formation_.units[i].unit->targetPosition += rotateVector(formation_.units[i].position, formation_.orientation);
			formation_.units[i].unit->moving = true;
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
		
	}
	
	void FormationController::moveFormation(const unsigned int p_usec)
	{
		
	}
	
}
