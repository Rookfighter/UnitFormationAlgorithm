#ifndef UFA_EVENT_MANAGER_HPP
#define UFA_EVENT_MANAGER_HPP

#include <vector>
#include <memory>
#include <SFML/Window.hpp>
#include "ufa/ui/EventHandler.hpp"

namespace ufa
{

	class EventManager
	{
	private:
		sf::Window &window_;
		std::vector<std::shared_ptr<EventHandler>> eventHandler_;
	public:
		EventManager(sf::Window &p_window);
		~EventManager();
		
		void addEventHandler(const std::shared_ptr<EventHandler> &p_eventHandler);
		void clearEventHandler();
		
		void processPendingEvents();
	};

}

#endif // UFA_EVENT_MANAGER_HPP
