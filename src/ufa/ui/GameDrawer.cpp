#include "ufa/ui/GameDrawer.hpp"

namespace ufa
{

	GameDrawer::GameDrawer(sf::RenderWindow &p_window)
	:window_(p_window)
	{	}

	GameDrawer::~GameDrawer()
	{	}
	
	UnitDrawer& GameDrawer::getUnitDrawer()
	{
		return unitDrawer_;
	}
	
	HudDrawer& GameDrawer::getHudDrawer()
	{
		return hudDrawer_;
	}
	
	sf::RenderWindow& GameDrawer::getWindow()
	{
		return window_;
	}
	
	void GameDrawer::redraw()
	{
		window_.clear(background_);
		
		unitDrawer_.draw(window_);
		hudDrawer_.draw(window_);
			
		window_.display();
	}
	
	void GameDrawer::setBackground(const sf::Color &p_color)
	{
		background_ = p_color;
	}
}

