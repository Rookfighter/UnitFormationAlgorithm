#ifndef UFA_HUD_DRAWER_HPP
#define UFA_HUD_DRAWER_HPP

#include <memory>
#include <list>
#include "ui/Drawable.hpp"

namespace ufa
{
	class HudDrawer: public Drawable
	{
	private:
		sf::View hud_;
		std::list<std::shared_ptr<Drawable>> hudElements_;
	public:
		HudDrawer();
		~HudDrawer();
		
		void addHudElement(const std::shared_ptr<Drawable> &p_hudElement);
		void clearHudElements();
		
		void draw(sf::RenderTarget &p_renderTarget);

	};

}

#endif // UFA_HUD_DRAWER_HPP
