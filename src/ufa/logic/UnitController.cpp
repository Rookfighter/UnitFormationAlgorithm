#include "ufa/logic/UnitController.hpp"
#include "ufa/general/Math.hpp"
#include "ufa/general/Logging.hpp"

#define POSITION_EPS 0.001f

namespace ufa
{
	UnitController::UnitController(const std::shared_ptr<Unit> &p_unit, World &p_world)
	:world_(p_world), unit_(p_unit)
	{
		
	}

	UnitController::~UnitController()
	{
	}
	
	void UnitController::step(const unsigned int p_usec)
	{
		setVelocityOfUnit(p_usec);
		moveUnit(p_usec);
	}
	
	void UnitController::setVelocityOfUnit(const unsigned int p_usec)
	{
		if(unit_->moving) {
			Vec2 diff = unit_->targetPosition - unit_->position;
			// check if distance is higher than maximum velocity and decide how to set velocity
			if(diff.lengthSQ() > (unit_->maxVelocity * unit_->maxVelocity * usecToSec(p_usec) * usecToSec(p_usec)))
				unit_->velocity = (diff / diff.length()) * unit_->maxVelocity;
			else
				unit_->velocity = diff / usecToSec(p_usec);
		}
			
	}
	
	void UnitController::moveUnit(const unsigned int p_usec)
	{
		if(unit_->moving) {
			Vec2 distanceToMove = unit_->velocity * usecToSec(p_usec);
			unit_->position += distanceToMove;
			
			if(sameFloat(unit_->position.x, unit_->targetPosition.x, POSITION_EPS) &&
			   sameFloat(unit_->position.y, unit_->targetPosition.y, POSITION_EPS)) {
				   unit_->moving = false;
				   PRINT_INFO("Reached Target: %s.", unit_->targetPosition.str().c_str());
			   }
				   
		}
	}
	
	void UnitController::setTarget(const Vec2 &p_target)
	{
		PRINT_INFO("Moving to Target: %s.", p_target.str().c_str());
		unit_->targetPosition = p_target;
		unit_->moving = true;
	}
		
	std::shared_ptr<Unit>& UnitController::getUnit()
	{
		return unit_;
	}
}

