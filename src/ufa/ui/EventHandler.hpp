#ifndef UFA_EVENT_HANDLER_HPP
#define UFA_EVENT_HANDLER_HPP

#include <SFML/Window.hpp>

namespace ufa
{
	/* This is a simple Interface for EventHandlers. In handleEvent() the given
	 * event should be processed. */
	class EventHandler
	{
	public:
		EventHandler() {}
		virtual ~EventHandler() {}
		virtual void handleEvent(const sf::Event &p_event) = 0;
	};

}

#endif // UFA_EVENT_HANDLER_HPP
