#ifndef UFA_SIMULATION_CONTROLLER_HPP
#define UFA_SIMULATION_CONTROLLER_HPP

#include <memory>
#include <list>
#include "ufa/logic/Controller.hpp"
#include "ufa/entities/World.hpp"

namespace ufa
{
	class SimulationController : public Controller
	{
	private:
		World &world_;
		std::list<std::shared_ptr<Controller>> controller_;
		
		void stepController(const unsigned int p_usec);
		void moveUnits(const unsigned int p_usec);
	public:
		SimulationController(World &p_world);
		~SimulationController();
		
		void addController(const std::shared_ptr<Controller> &p_controller);
		void clearController();
		
		void step(const unsigned int p_usec);
	};

}

#endif
