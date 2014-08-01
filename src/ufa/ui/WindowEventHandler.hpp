#ifndef UFA_WINDOW_EVENT_HANDLER_HPP
#define UFA_WINDOW_EVENT_HANDLER_HPP

#include <memory>
#include "ufa/ui/EventHandler.hpp"
#include "ufa/ui/DrawWindow.hpp"

namespace ufa
{
	class WindowEventHandler: public EventHandler
	{
	private:
		const std::shared_ptr<DrawWindow> window_;
	public:
		WindowEventHandler(const std::shared_ptr<DrawWindow> &p_window);
		~WindowEventHandler();
		
		void handleEvent(const sf::Event &p_event);
	};

}

#endif // UFA_WINDOW_EVENT_HANDLER_HPP
