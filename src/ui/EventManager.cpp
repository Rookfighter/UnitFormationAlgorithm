#include "ui/EventManager.hpp"

namespace ufa
{

	EventManager::EventManager(sf::Window &p_window)
	:window_(p_window)
	{
	}

	EventManager::~EventManager()
	{
	}
	
	void EventManager::addEventHandler(const std::shared_ptr<EventHandler> &p_eventHandler)
	{
		eventHandler_.push_back(p_eventHandler);
	}
	
	void EventManager::clearEventHandler()
	{
		eventHandler_.clear();
	}
	
	void EventManager::processPendingEvents()
	{
		sf::Event event;
		while(window_.pollEvent(event)) {
			// give the event to each eventhandler
			for(int i = 0; i < eventHandler_.size(); ++i)
				eventHandler_[i]->handleEvent(event);
		}
	}

}

