#include "ufa/ui/MouseEventHandler.hpp"

namespace ufa
{

	MouseEventHandler::MouseEventHandler(sf::Window &p_window)
	:rightPressed_(false), leftPressed_(false), window_(p_window)
	{
	}

	MouseEventHandler::~MouseEventHandler()
	{
	}
	
	void MouseEventHandler::handleEvent(const sf::Event &p_event)
	{
		switch(p_event.type) {
			case sf::Event::MouseButtonPressed:
				break;
			case sf::Event::MouseButtonReleased:
				break;
			case sf::Event::MouseEntered:
				break;
			case sf::Event::MouseLeft:
				break;
			case sf::Event::MouseMoved:
				break;
			case sf::Event::MouseWheelMoved:
				break;
			default:
				break;
		}
	}
}

