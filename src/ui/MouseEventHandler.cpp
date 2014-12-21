#include <cmath>
#include "ui/MouseEventHandler.hpp"
#include "general/Logging.hpp"

namespace ufa
{

	MouseEventHandler::MouseEventHandler(GameDrawer &p_gameDrawer, GameFactory &p_factory)
	:rightPressed_(false), leftPressed_(false), gameDrawer_(p_gameDrawer), mouseBox_(new MouseBox()), gameFactory_(p_factory)
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
				else if(p_event.mouseButton.button == sf::Mouse::Right)
					processRightMouseButtonPressed(p_event);
				break;
			case sf::Event::MouseButtonReleased:
				if(p_event.mouseButton.button == sf::Mouse::Left)
					processLeftMouseButtonReleased(p_event);
				else if(p_event.mouseButton.button == sf::Mouse::Right)
					processRightMouseButtonReleased(p_event);
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
		//release all selected drawables
		for(std::shared_ptr<DrawableUnit> unit : selectedUnits_)
			unit->select(false);
		
		// get all drawables that are in the range of the MouseBox
		selectedUnits_ = gameDrawer_.getUnitDrawer().getUnitsInRect(mouseBox_->topLeft(gameDrawer_.getWindow()), mouseBox_->size(gameDrawer_.getWindow()));
		
		for(std::shared_ptr<DrawableUnit> unit : selectedUnits_)
			unit->select(true);
		
		// create formation
		std::vector<std::shared_ptr<Unit>> units;
		units.reserve(selectedUnits_.size());
		for(std::shared_ptr<DrawableUnit> unit : selectedUnits_)
			units.push_back(unit->getUnitController()->getUnit());
		formationController_ = gameFactory_.createBlockFormation(units);
	}
	
	void MouseEventHandler::processRightMouseButtonPressed(const sf::Event &p_event)
	{
		if(!rightPressed_) {
			rightPressed_ = true;
		}
	}
	
	void MouseEventHandler::processRightMouseButtonReleased(const sf::Event &p_event)
	{
		if(rightPressed_) {
			rightPressed_ = false;
			
			sf::Vector2f targetPos = gameDrawer_.getWindow().mapPixelToCoords(sf::Vector2i(p_event.mouseButton.x, p_event.mouseButton.y));
			formationController_->moveTo(Vec2(targetPos.x, targetPos.y));
		}
	}
	
	void MouseEventHandler::processMouseMoved(const sf::Event &p_event)
	{
		if(leftPressed_) {
			mouseBox_->pointB = sf::Vector2i(p_event.mouseMove.x, p_event.mouseMove.y);
		}
	}
}

