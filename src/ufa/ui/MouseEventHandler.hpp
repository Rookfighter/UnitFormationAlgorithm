#ifndef UFA_MOUSE_HANDLER_EVENT_HPP
#define UFA_MOUSE_HANDLER_EVENT_HPP

#include <memory>
#include "ufa/ui/EventHandler.hpp"
#include "ufa/ui/DrawWindow.hpp"
#include "ufa/ui/MouseBox.hpp"

namespace ufa
{
	/* The MouseEventHandler handles all MouseEvents. */
	class MouseEventHandler: public EventHandler
	{
	private:
		bool rightPressed_, leftPressed_;
		std::shared_ptr<DrawWindow> window_;
		std::shared_ptr<MouseBox> mouseBox_;
		
		void processLeftMouseButtonPressed(const sf::Event &p_event);
		void processLeftMouseButtonReleased(const sf::Event &p_event);
		void selectUnits();
		void processMouseMoved(const sf::Event &p_event);
	public:
		MouseEventHandler(const std::shared_ptr<DrawWindow> &p_window);
		~MouseEventHandler();
			
		void handleEvent(const sf::Event &p_event);
	};
}

#endif
