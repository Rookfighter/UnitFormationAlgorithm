#include <cmath>
#include "ufa/ui/MouseEventHandler.hpp"
#include "ufa/general/Logging.hpp"

namespace ufa
{

	MouseEventHandler::MouseEventHandler(GameDrawer &p_gameDrawer)
	:rightPressed_(false), leftPressed_(false), gameDrawer_(p_gameDrawer), mouseBox_(new MouseBox())
	{
		gameDrawer_.getHudDrawer().addHudElement(mouseBox_);
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
			mouseBox_->pointA = sf::Vector2i(p_event.mouseButton.x, p_event.mouseButton.y);
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
		std::list<std::shared_ptr<DrawableUnit>>::iterator it;
		//release all selected drawables
		for(it = selectedUnits_.begin(); it != selectedUnits_.end(); ++it)
			(*it)->select(false);
		
		// get all drawables that are in the range of the MouseBox
		selectedUnits_ = gameDrawer_.getUnitDrawer().getUnitsInRect(mouseBox_->topLeft(gameDrawer_.getWindow()), mouseBox_->size(gameDrawer_.getWindow()));
		
		for(it = selectedUnits_.begin(); it != selectedUnits_.end(); ++it)
			(*it)->select(true);
	}
	
	void MouseEventHandler::processMouseMoved(const sf::Event &p_event)
	{
		if(leftPressed_) {
			mouseBox_->pointB = sf::Vector2i(p_event.mouseMove.x, p_event.mouseMove.y);
		}
	}
}

