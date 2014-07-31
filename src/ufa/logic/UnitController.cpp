#include "ufa/logic/UnitController.hpp"
#include "ufa/general/Math.hpp"

namespace ufa
{
	UnitController::UnitController(const std::shared_ptr<World> &p_world)
	:world_(p_world)
	{ }

	UnitController::~UnitController()
	{ }
	
	void UnitController::step(const unsigned int p_usec)
	{
		setVelocityOfUnits();
		moveUnits(p_usec);
	}
	
	void UnitController::setVelocityOfUnits()
	{
		std::list<std::shared_ptr<Unit>>::iterator it;
		for(it = world_->units.begin(); it != world_->units.end(); ++it) {
			std::shared_ptr<Unit> currentUnit = *it;
			if(currentUnit->moving) {
				Vec2 diff = currentUnit->targetPosition - currentUnit->position;
				
				// check if distance is higher than maximum velocity and decide how to set velocity
				if(diff.lengthSQ() > (currentUnit->maxVelocity * currentUnit->maxVelocity))
					currentUnit->velocity = (diff / diff.length()) * currentUnit->maxVelocity;
				else
					currentUnit->velocity = diff;
			}
		}
	}
	
	void UnitController::moveUnits(const unsigned int p_usec)
	{
		std::list<std::shared_ptr<Unit>>::iterator it;
		for(it = world_->units.begin(); it != world_->units.end(); ++it) {
			std::shared_ptr<Unit> currentUnit = *it;
			if(currentUnit->moving) {
				Vec2 distanceToMove = (currentUnit->velocity * p_usec) / USEC_PER_SEC;
				currentUnit->position += distanceToMove;
			}
		}
	}
}

