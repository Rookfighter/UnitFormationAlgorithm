#include "ufa/logic/SimulationController.hpp"

namespace ufa
{

	SimulationController::SimulationController()
	: controller_()
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
		std::list<std::shared_ptr<Controller>>::iterator it;
		for(it = controller_.begin(); it != controller_.end(); ++it)
			(*it)->step(p_usec);
	}

}

