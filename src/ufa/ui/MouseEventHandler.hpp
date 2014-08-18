#ifndef UFA_MOUSE_HANDLER_EVENT_HPP
#define UFA_MOUSE_HANDLER_EVENT_HPP

#include <memory>
#include "ufa/ui/EventHandler.hpp"
#include "ufa/ui/GameDrawer.hpp"
#include "ufa/ui/MouseBox.hpp"

namespace ufa
{
	/* The MouseEventHandler handles all mouse events. */
	class MouseEventHandler: public EventHandler
	{
	private:
		bool rightPressed_, leftPressed_;
		GameDrawer& gameDrawer_;
		std::shared_ptr<MouseBox> mouseBox_;
		std::list<std::shared_ptr<DrawableUnit>> selectedUnits_;
		
		void processLeftMouseButtonPressed(const sf::Event &p_event);
		void processLeftMouseButtonReleased(const sf::Event &p_event);
		void selectUnits();
		void processMouseMoved(const sf::Event &p_event);
	public:
		MouseEventHandler(GameDrawer &p_gameDrawer);
		~MouseEventHandler();
			
		void handleEvent(const sf::Event &p_event);
	};
}

#endif
