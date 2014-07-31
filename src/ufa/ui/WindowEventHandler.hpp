#ifndef UFA_WINDOW_EVENT_HANDLER_HPP
#define UFA_WINDOW_EVENT_HANDLER_HPP

#include "ufa/ui/EventHandler.hpp"

namespace ufa
{

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

#endif // UFA_WINDOW_EVENT_HANDLER_HPP
