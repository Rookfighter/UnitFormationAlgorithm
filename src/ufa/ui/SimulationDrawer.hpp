#ifndef UFA_SIMULATION_DRAWER_HPP
#define UFA_SIMULATION_DRAWER_HPP

#include <memory>
#include <list>
#include <vector>
#include <SFML/Graphics.hpp>
#include "ufa/entities/World.hpp"
#include "ufa/ui/Drawable.hpp"

namespace ufa
{
	class SimulationDrawer
	{
	private:
		std::shared_ptr<World> world_;
		std::list<std::shared_ptr<Drawable>> drawObjects_;
		std::list<std::shared_ptr<Drawable>> hudElements_;
		
		sf::RenderTexture hud;
		
		void drawDrawObjects(sf::RenderTarget &p_renderTarget);
		void drawHudElements(sf::RenderTarget &p_renderTarget);
	public:
		SimulationDrawer(const std::shared_ptr<World> &p_world);
		~SimulationDrawer();
		
		void addDrawObject(const std::shared_ptr<Drawable> &p_drawObject);
		void addHudElement(const std::shared_ptr<Drawable> &p_hudElement);
		
		void drawSimulation(sf::RenderTarget &p_renderTarget);
		
		std::vector<std::shared_ptr<Drawable>> getObjectsInRect(const sf::Vector2f &p_topLeft, const sf::Vector2f &p_size);
	};

}

#endif // UFA_SIMULATION_DRAWER_HPP
