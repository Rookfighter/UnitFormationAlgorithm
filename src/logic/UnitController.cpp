#include "logic/UnitController.hpp"
#include "general/Math.hpp"

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
	}

	void UnitController::setVelocityOfUnit(const unsigned int p_usec)
	{
		if(unit_->moving && unit_->reachedTarget(POSITION_EPS)) {
			unit_->moving = false;
		}
		
		if(unit_->moving) {
			Vec2 diff = unit_->targetPosition - unit_->position;
			// check if distance is higher than maximum velocity and decide how to set velocity
			if(diff.lengthSQ() > (unit_->maxVelocity * unit_->maxVelocity * usecToSec(p_usec) * usecToSec(p_usec)))
				unit_->velocity = (diff / diff.length()) * unit_->maxVelocity;
			else
				unit_->velocity = diff / usecToSec(p_usec);
		}

	}

	std::shared_ptr<Unit>& UnitController::getUnit()
	{
		return unit_;
	}
}
