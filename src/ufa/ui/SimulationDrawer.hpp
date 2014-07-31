#ifndef UFA_SIMULATION_DRAWER_HPP
#define UFA_SIMULATION_DRAWER_HPP

#include <SFML/Graphics.hpp>
#include "ufa/entities/World.hpp"

namespace ufa
{

	class SimulationDrawer
	{
	private:
		std::shared_ptr<World> world_;
		
		void drawUnit(sf::RenderTarget &p_renderTarget, const std::shared_ptr<Unit> p_unit);
	public:
		SimulationDrawer(const std::shared_ptr<World> &p_world);
		~SimulationDrawer();
		
		void drawSimulation(sf::RenderTarget &p_renderTarget);
	};

}

#endif // UFA_SIMULATION_DRAWER_HPP
