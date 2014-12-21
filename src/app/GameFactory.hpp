#ifndef UFA_GAME_FACTORY_HPP
#define UFA_GAME_FACTORY_HPP

#include "entities/World.hpp"
#include "logic/SimulationController.hpp"
#include "logic/UnitController.hpp"
#include "logic/BlockFormationController.hpp"
#include "ui/DrawableUnit.hpp"
#include "ui/GameDrawer.hpp"
#include "ui/EventManager.hpp"
#include "ui/MouseEventHandler.hpp"
#include "ui/WindowEventHandler.hpp"

namespace ufa
{
	typedef struct {
		std::shared_ptr<Unit> unit;
		std::shared_ptr<UnitController> controller;
		std::shared_ptr<DrawableUnit> drawable;
	} CreatedUnit;
	
	class MouseEventHandler;
	class GameFactory
	{
	private:
		World world_;
		SimulationController simController_;
		
		sf::RenderWindow window_;
		GameDrawer gameDrawer_;
		EventManager eventManager_;
	public:
		GameFactory();
		~GameFactory();
		
		CreatedUnit createMeleeUnit();
		CreatedUnit createRangedUnit();
		std::shared_ptr<BlockFormationController> createBlockFormation(const std::vector<std::shared_ptr<Unit>> &p_units);
		
		
		std::shared_ptr<WindowEventHandler> createWindowEventHandler();
		std::shared_ptr<MouseEventHandler> createMouseEventHandler();
		
		World& getWorld();
		SimulationController& getSimulationController();
		GameDrawer& getGameDrawer();
		sf::RenderWindow& getRenderWindow();
		EventManager& getEventManager();

	};
}

#endif
