#ifndef UFA_SIMULATION_DRAWER_HPP
#define UFA_SIMULATION_DRAWER_HPP

#include <memory>
#include <list>
#include <SFML/Graphics.hpp>
#include "ui/UnitDrawer.hpp"
#include "ui/HudDrawer.hpp"

namespace ufa
{
	/* The SimulationDrawer draws all Objects in the simulation on the given RenderTarget.
	 * To add Objects add them to the drawObjects list.
	 * HUD elements can also be added. Their position should be set relative to
	 * the screen origin. SFML Views don't have to be considered. */
	class GameDrawer
	{
	private:
		sf::RenderWindow &window_;
		
		UnitDrawer unitDrawer_;
		HudDrawer hudDrawer_;
		
		sf::Color background_;
	public:
		GameDrawer(sf::RenderWindow &p_window);
		~GameDrawer();
		
		void redraw();
		
		void setBackground(const sf::Color &p_color);
		
		UnitDrawer& getUnitDrawer();
		HudDrawer& getHudDrawer();
		
		sf::RenderWindow& getWindow();
	};

}

#endif // UFA_SIMULATION_DRAWER_HPP
