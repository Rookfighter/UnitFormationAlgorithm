#ifndef UFA_WINDOW_EVENT_HANDLER_HPP
#define UFA_WINDOW_EVENT_HANDLER_HPP

#include <memory>
#include "ufa/ui/EventHandler.hpp"

namespace ufa
{
	/* The WindowEventHandler handles all events related to the SFML
	 * window. */
	class WindowEventHandler: public EventHandler
	{
	private:
		sf::Window &window_;
	public:
		WindowEventHandler(sf::Window &p_window);
		~WindowEventHandler();
		
		void handleEvent(const sf::Event &p_event);
	};

}

#endif
