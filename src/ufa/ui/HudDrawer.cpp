#include "ufa/ui/HudDrawer.hpp"

namespace ufa
{

	HudDrawer::HudDrawer()
	{
	}

	HudDrawer::~HudDrawer()
	{
	}


	void HudDrawer::addHudElement(const std::shared_ptr<Drawable> &p_hudElement)
	{
		hudElements_.push_back(p_hudElement);
	}
	
	void HudDrawer::clearHudElements()
	{
		hudElements_.clear();
	}
	
	void HudDrawer::draw(sf::RenderTarget &p_renderTarget)
	{
		std::list<std::shared_ptr<Drawable>>::iterator it;
		for(it = hudElements_.begin(); it != hudElements_.end(); ++it)
			(*it)->draw(p_renderTarget);
	}

}

