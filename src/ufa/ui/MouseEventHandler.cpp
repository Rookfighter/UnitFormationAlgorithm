#include <cmath>
#include "ufa/ui/MouseEventHandler.hpp"
#include "ufa/general/Logging.hpp"

namespace ufa
{

	MouseEventHandler::MouseEventHandler(const std::shared_ptr<DrawWindow> &p_window)
	:rightPressed_(false), leftPressed_(false), window_(p_window), mouseBox_(new MouseBox)
	{
		window_->getDrawer().hudElements.push_back(mouseBox_);
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
			mouseBox_->pointA = sf::Vector2f(p_event.mouseButton.x, p_event.mouseButton.y);
			mouseBox_->pointB = mouseBox_->pointA;
		}
	}
	
	void MouseEventHandler::processLeftMouseButtonReleased(const sf::Event &p_event)
	{
		if(leftPressed_) {
			leftPressed_ = false;
			mouseBox_->drawBox = false;
			
			selectUnits();
		}
	}
	
	void MouseEventHandler::selectUnits()
	{
		std::list<std::shared_ptr<Drawable>>::iterator it;
		
		//release all selected drawables
		for(it = window_->getDrawer().drawObjects.begin(); it != window_->getDrawer().drawObjects.end(); ++it)
			(*it)->selected = false;
		
		// get all drawables that are in the range of the MouseBox
		float x = mouseBox_->getPosition().x +
				  window_->getRenderWindow().getView().getCenter().x -
				  (window_->getRenderWindow().getSize().x / 2);
		float y = mouseBox_->getPosition().y +
				  window_->getRenderWindow().getView().getCenter().y -
				  (window_->getRenderWindow().getSize().y / 2);
		std::list<std::shared_ptr<Drawable>> drawablesInRect= window_->getDrawer().getObjectsInRect(sf::Vector2f(x,y), mouseBox_->getSize());
		for(it = drawablesInRect.begin(); it != drawablesInRect.end(); ++it)
			(*it)->selected = true;
	}
	
	void MouseEventHandler::processMouseMoved(const sf::Event &p_event)
	{
		if(leftPressed_) {
			mouseBox_->pointB = sf::Vector2f(p_event.mouseMove.x, p_event.mouseMove.y);
		}
	}
}

