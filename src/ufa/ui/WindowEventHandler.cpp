#include "ufa/ui/WindowEventHandler.hpp"

namespace ufa
{

	WindowEventHandler::WindowEventHandler(const std::shared_ptr<DrawWindow> &p_window)
	:window_(p_window) {	}

	WindowEventHandler::~WindowEventHandler()
	{
	}
	
	void WindowEventHandler::handleEvent(const sf::Event &p_event)
	{
		switch(p_event.type) {
			case sf::Event::Closed:
				window_->getRenderWindow().close();
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

