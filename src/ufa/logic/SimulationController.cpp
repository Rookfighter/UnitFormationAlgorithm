#include "ufa/logic/SimulationController.hpp"
#include "ufa/general/Math.hpp"

namespace ufa
{

	SimulationController::SimulationController(World &p_world)
	: world_(p_world), controller_()
	{	}

	SimulationController::~SimulationController()
	{	}
	
	void SimulationController::addController(const std::shared_ptr<Controller> &p_controller)
	{
		controller_.push_back(p_controller);
	}
	
	void SimulationController::clearController()
	{
		controller_.clear();
	}
	
	void SimulationController::step(const unsigned int p_usec)
	{
		stepController(p_usec);
		moveUnits(p_usec);
	}
	
	void SimulationController::stepController(const unsigned int p_usec)
	{
		for(std::shared_ptr<Controller> controller : controller_)
			controller->step(p_usec);
	}
	
	void SimulationController::moveUnits(const unsigned int p_usec)
	{
		for(std::shared_ptr<Unit> unit : world_.units) {
			if(unit->moving) {
				Vec2 distanceToMove = unit->velocity * usecToSec(p_usec);
				unit->position += distanceToMove;
			}
		}
	}

}

