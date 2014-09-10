#ifndef UFA_MOUSE_HANDLER_EVENT_HPP
#define UFA_MOUSE_HANDLER_EVENT_HPP

//TODO GameFactory lies in higher layer!
#include <memory>
#include "ufa/app/GameFactory.hpp"
#include "ufa/ui/EventHandler.hpp"
#include "ufa/ui/GameDrawer.hpp"
#include "ufa/ui/MouseBox.hpp"

namespace ufa
{
	class GameFactory;
	/* The MouseEventHandler handles all mouse events. */
	class MouseEventHandler: public EventHandler
	{
	private:
		bool rightPressed_, leftPressed_;
		GameDrawer& gameDrawer_;
		GameFactory& gameFactory_;
		std::shared_ptr<MouseBox> mouseBox_;
		std::list<std::shared_ptr<DrawableUnit>> selectedUnits_;
		
		void processLeftMouseButtonPressed(const sf::Event &p_event);
		void processLeftMouseButtonReleased(const sf::Event &p_event);
		void processRightMouseButtonPressed(const sf::Event &p_event);
		void processRightMouseButtonReleased(const sf::Event &p_event);
		void selectUnits();
		void processMouseMoved(const sf::Event &p_event);
	public:
		MouseEventHandler(GameDrawer &p_gameDrawer, GameFactory &p_factory);
		~MouseEventHandler();
			
		void handleEvent(const sf::Event &p_event);
	};
}

#endif
