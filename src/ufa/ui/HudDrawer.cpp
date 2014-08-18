#include "ufa/ui/HudDrawer.hpp"

namespace ufa
{

	HudDrawer::HudDrawer()
	:hud_()
	{
		hud_.setCenter(0,0);
		hud_.setRotation(0);
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
		sf::View last = p_renderTarget.getView();
		// set hud size to window size, so there is no scaling
		hud_.setSize(p_renderTarget.getSize().x, p_renderTarget.getSize().y);
		//set hud center to half of its size, so hud objects are placed at the right position
		hud_.setCenter(hud_.getSize().x / 2, hud_.getSize().y / 2);
		p_renderTarget.setView(hud_);
		
		std::list<std::shared_ptr<Drawable>>::iterator it;
		for(it = hudElements_.begin(); it != hudElements_.end(); ++it)
			(*it)->draw(p_renderTarget);
			
		p_renderTarget.setView(last);
	}

}

