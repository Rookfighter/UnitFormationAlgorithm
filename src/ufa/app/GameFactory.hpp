#ifndef UFA_GAME_FACTORY_HPP
#define UFA_GAME_FACTORY_HPP

#include "ufa/entities/World.hpp"
#include "ufa/logic/SimulationController.hpp"
#include "ufa/logic/UnitController.hpp"
#include "ufa/logic/BlockFormationController.hpp"
#include "ufa/ui/DrawableUnit.hpp"
#include "ufa/ui/GameDrawer.hpp"
#include "ufa/ui/Eventmanager.hpp"
#include "ufa/ui/MouseEventHandler.hpp"
#include "ufa/ui/WindowEventHandler.hpp"

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
