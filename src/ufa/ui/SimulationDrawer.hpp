#ifndef UFA_SIMULATION_DRAWER_HPP
#define UFA_SIMULATION_DRAWER_HPP

#include <memory>
#include <list>
#include <SFML/Graphics.hpp>
#include "ufa/entities/World.hpp"
#include "ufa/ui/Drawable.hpp"

namespace ufa
{
	/* The SimulationDrawer draws all Objects in the simulation on the given RenderTarget.
	 * To add Objects add them to the drawObjects list.
	 * HUD elements can also be added. Their position should be set relative to
	 * the screen origin. SFML Views don't have to be considered. */
	class SimulationDrawer
	{
	private:
		std::shared_ptr<World> world_;
		sf::RenderTexture hud;
		
		void drawDrawObjects(sf::RenderTarget &p_renderTarget);
		void drawHudElements(sf::RenderTarget &p_renderTarget);
	public:
		std::list<std::shared_ptr<Drawable>> drawObjects;
		std::list<std::shared_ptr<Drawable>> hudElements;
		
		SimulationDrawer(const std::shared_ptr<World> &p_world);
		~SimulationDrawer();
		
		void drawSimulation(sf::RenderTarget &p_renderTarget);
		
		std::list<std::shared_ptr<Drawable>> getObjectsInRect(const sf::Vector2f &p_topLeft, const sf::Vector2f &p_size);
	};

}

#endif // UFA_SIMULATION_DRAWER_HPP
