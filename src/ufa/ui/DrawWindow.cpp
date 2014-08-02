#include "ufa/ui/DrawWindow.hpp"

#define APPLICATION_NAME "UnitFormationAlgorithm"
#define BACKGROUND_COLOR sf::Color::Black

namespace ufa
{

	DrawWindow::DrawWindow(const unsigned int p_width, const unsigned int p_height, const std::shared_ptr<World> &p_world)
	: window_(sf::VideoMode(p_width, p_height), APPLICATION_NAME), drawer_(p_world)
	{	}
	
	DrawWindow::~DrawWindow()
	{	}

	void DrawWindow::addEventHandler(const std::shared_ptr<EventHandler> &p_eventHandler)
	{
		eventHandler_.push_back(p_eventHandler);
	}
	
	void DrawWindow::clearEventHandler()
	{
		eventHandler_.clear();
	}
	
	void DrawWindow::processPendingEvents()
	{
		sf::Event event;
		while(window_.pollEvent(event)) {
			// give the event to each eventhandler
			for(int i = 0; i < eventHandler_.size(); ++i)
				eventHandler_[i]->handleEvent(event);
		}
	}
	
	void DrawWindow::redraw()
	{
		window_.clear(BACKGROUND_COLOR);
		drawer_.drawSimulation(window_);
		window_.display();
	}
	
	sf::RenderWindow& DrawWindow::getRenderWindow()
	{
		return window_;
	}
	
	SimulationDrawer& DrawWindow::getDrawer()
	{
		return drawer_;
	}
}

