#include "ui/WindowEventHandler.hpp"

namespace ufa
{

	WindowEventHandler::WindowEventHandler(sf::Window &p_window)
	:window_(p_window) {	}

	WindowEventHandler::~WindowEventHandler()
	{
	}
	
	void WindowEventHandler::handleEvent(const sf::Event &p_event)
	{
		switch(p_event.type) {
			case sf::Event::Closed:
				window_.close();
				break;
			case sf::Event::LostFocus:
				break;
			case sf::Event::GainedFocus:
				break;
			case sf::Event::Resized:
				break;
			default:
				break;
		}
	}


}

