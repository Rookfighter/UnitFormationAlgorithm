#ifndef UFA_DRAW_WINDOW_HPP
#define UFA_DRAW_WINDOW_HPP

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "ufa/ui/EventHandler.hpp"
#include "ufa/ui/SimulationDrawer.hpp"
#include "ufa/entities/World.hpp"

namespace ufa
{

	class DrawWindow
	{
	private:
		sf::RenderWindow window_;
		std::vector<std::shared_ptr<EventHandler>> eventHandler_;
		SimulationDrawer drawer_;
	public:
		DrawWindow(const unsigned int p_width, const unsigned int p_height, const std::shared_ptr<World> &p_world);
		~DrawWindow();
		
		void addEventHandler(const std::shared_ptr<EventHandler> &p_eventHandler);
		void clearEventHandler();
		
		void processPendingEvents();
		void redraw();
		
		sf::RenderWindow& getRenderWindow();
		SimulationDrawer& getDrawer();
	};

}

#endif // UFA_DRAW_WINDOW_HPP
