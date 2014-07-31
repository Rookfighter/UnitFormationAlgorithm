#ifndef UFA_MOUSE_HANDLER_EVENT_HPP
#define UFA_MOUSE_HANDLER_EVENT_HPP

#include "ufa/ui/EventHandler.hpp"

namespace ufa
{
	class MouseEventHandler: public EventHandler
	{
	private:
		bool rightPressed_, leftPressed_;
		sf::Window &window_;
	public:
		MouseEventHandler(sf::Window &p_window);
		~MouseEventHandler();
			
		void handleEvent(const sf::Event &p_event);
	};
}

#endif
