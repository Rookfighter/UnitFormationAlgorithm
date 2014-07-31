#ifndef UFA_SIMULATION_CONTROLLER_HPP
#define UFA_SIMULATION_CONTROLLER_HPP

#include <memory>
#include <list>
#include "ufa/logic/Controller.hpp"

namespace ufa
{
	class SimulationController : public Controller
	{
	private:
		std::list<std::shared_ptr<Controller>> controller_;
	public:
		SimulationController();
		~SimulationController();
		
		void addController(const std::shared_ptr<Controller> &p_controller);
		void clearController();
		
		void step(const unsigned int p_usec);
	};

}

#endif
