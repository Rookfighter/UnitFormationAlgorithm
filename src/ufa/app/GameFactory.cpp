#include "ufa/app/GameFactory.hpp"

#define DEFAULT_WIDTH 800
#define DEFAULT_HEIGHT 600
#define DEFAULT_NAME "Default"

namespace ufa
{

	GameFactory::GameFactory()
		:world_(), simController_(), window_(sf::VideoMode(DEFAULT_WIDTH, DEFAULT_HEIGHT), DEFAULT_NAME),
		 gameDrawer_(window_), eventManager_(window_)
	{
		
	}

	GameFactory::~GameFactory()
	{

	}

	CreatedUnit GameFactory::createMeleeUnit()
	{
		CreatedUnit result;
		result.unit = std::shared_ptr<Unit>(new MeleeUnit());
		result.controller = std::shared_ptr<UnitController>(new UnitController(result.unit, world_));
		result.drawable = std::shared_ptr<DrawableUnit>(new DrawableUnit(result.controller));

		world_.units.push_back(result.unit);
		simController_.addController(result.controller);
		gameDrawer_.getUnitDrawer().addUnit(result.drawable);

		return result;
	}

	CreatedUnit GameFactory::createRangedUnit()
	{
		CreatedUnit result;
		result.unit = std::shared_ptr<Unit>(new RangedUnit());
		result.controller = std::shared_ptr<UnitController>(new UnitController(result.unit, world_));
		result.drawable = std::shared_ptr<DrawableUnit>(new DrawableUnit(result.controller));

		world_.units.push_back(result.unit);
		simController_.addController(result.controller);
		gameDrawer_.getUnitDrawer().addUnit(result.drawable);

		return result;
	}

	std::shared_ptr<WindowEventHandler> GameFactory::createWindowEventHandler()
	{
		std::shared_ptr<WindowEventHandler> windowHandler(new WindowEventHandler(window_));
		eventManager_.addEventHandler(windowHandler);
		return windowHandler;
	}


	std::shared_ptr<MouseEventHandler> GameFactory::createMouseEventHandler()
	{
		std::shared_ptr<MouseEventHandler> mouseHandler(new MouseEventHandler(gameDrawer_));
		eventManager_.addEventHandler(mouseHandler);
		return mouseHandler;
	}

	World& GameFactory::getWorld()
	{
		return world_;
	}

	SimulationController& GameFactory::getSimulationController()
	{
		return simController_;
	}

	GameDrawer& GameFactory::getGameDrawer()
	{
		return gameDrawer_;
	}

	sf::RenderWindow& GameFactory::getRenderWindow()
	{
		return window_;
	}

	EventManager& GameFactory::getEventManager()
	{
		return eventManager_;
	}


}
