#include <cmath>
#include "ufa/ui/MouseEventHandler.hpp"
#include "ufa/general/Logging.hpp"

namespace ufa
{

	MouseEventHandler::MouseEventHandler(const std::shared_ptr<DrawWindow> &p_window)
	:rightPressed_(false), leftPressed_(false), window_(p_window), mouseBox_(new MouseBox)
	{
		window_->getDrawer().addHudElement(mouseBox_);
	}

	MouseEventHandler::~MouseEventHandler()
	{
	}
	
	void MouseEventHandler::handleEvent(const sf::Event &p_event)
	{
		switch(p_event.type) {
			case sf::Event::MouseButtonPressed:
				if(p_event.mouseButton.button == sf::Mouse::Left)
					processLeftMouseButtonPressed(p_event);
				break;
			case sf::Event::MouseButtonReleased:
				if(p_event.mouseButton.button == sf::Mouse::Left)
					processLeftMouseButtonReleased(p_event);
				break;
			case sf::Event::MouseEntered:
				break;
			case sf::Event::MouseLeft:
				break;
			case sf::Event::MouseMoved:
				processMouseMoved(p_event);
				break;
			case sf::Event::MouseWheelMoved:
				break;
			default:
				break;
		}
	}
	
	void MouseEventHandler::processLeftMouseButtonPressed(const sf::Event &p_event)
	{
		if(!leftPressed_) {
			leftPressed_ = true;
			mouseBox_->drawBox = true;
			leftStart.x = p_event.mouseButton.x;
			leftStart.y = p_event.mouseButton.y;
			mouseBox_->topLeft = leftStart;
			mouseBox_->size.x = 0;
			mouseBox_->size.y = 0;
		}
	}
	
	void MouseEventHandler::processLeftMouseButtonReleased(const sf::Event &p_event)
	{
		if(leftPressed_) {
			leftPressed_ = false;
			mouseBox_->drawBox = false;
		}
	}
	
	void MouseEventHandler::processMouseMoved(const sf::Event &p_event)
	{
		if(leftPressed_) {
			if(p_event.mouseMove.x < leftStart.x)
				mouseBox_->topLeft.x = p_event.mouseMove.x;
			else
				mouseBox_->topLeft.x = leftStart.x;
			
			if(p_event.mouseMove.y < leftStart.y)
				mouseBox_->topLeft.y = p_event.mouseMove.y;
			else
				mouseBox_->topLeft.y = leftStart.y;
			
			mouseBox_->size.x = fabs(p_event.mouseMove.x - leftStart.x);
			mouseBox_->size.y = fabs(p_event.mouseMove.y - leftStart.y);
		}
	}
}

