#include <memory>
#include "ufa/entities/World.hpp"

#include "ufa/logic/SimulationController.hpp"
#include "ufa/logic/UnitController.hpp"

#include "ufa/ui/EventManager.hpp"
#include "ufa/ui/MouseEventHandler.hpp"
#include "ufa/ui/WindowEventHandler.hpp"
#include "ufa/ui/GameDrawer.hpp"

#include "ufa/general/Math.hpp"
#include "ufa/general/Logging.hpp"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define APP_NAME "UnitFormationAlgorithm"
#define FPS 30

ufa::World world;
sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), APP_NAME);
ufa::EventManager eventManager(window);
ufa::GameDrawer gameDrawer(window);
ufa::SimulationController simulationController;

std::shared_ptr<ufa::WindowEventHandler> windowHandler(new ufa::WindowEventHandler(window));
std::shared_ptr<ufa::MouseEventHandler> mouseHandler(new ufa::MouseEventHandler(gameDrawer));
std::shared_ptr<ufa::UnitController> unitController(new ufa::UnitController(world));
std::shared_ptr<ufa::Unit> unit(new ufa::Unit());
std::shared_ptr<ufa::DrawableUnit> drawUnit(new ufa::DrawableUnit(unit));

static void init()
{
	unit->position.set(0,0);
	unit->radius = 1;
	
	world.units.push_back(unit);
	simulationController.addController(unitController);
	
	eventManager.addEventHandler(windowHandler);
	eventManager.addEventHandler(mouseHandler);
	
	gameDrawer.getUnitDrawer().addUnit(drawUnit);
}

static void run()
{
	sf::Time loopTime = sf::microseconds(FPS_TO_USEC(FPS));
	sf::Time elapsed;
	sf::Clock clock;
	clock.restart();
	while(window.isOpen()) {
		simulationController.step(loopTime.asMicroseconds());
		gameDrawer.redraw();
		eventManager.processPendingEvents();
		
		elapsed = clock.getElapsedTime();
		if(loopTime > elapsed)
			sf::sleep(loopTime - elapsed);
		else
			PRINT_WARN("Gameloop timed out.");
		clock.restart();
	}
}

int main()
{
	try {
		init();
		run();
	} catch(std::exception &e) {
		PRINT_ERROR("Catched exception: %s.", e.what());
	} catch(...) {
		PRINT_ERROR("Catched anything.");
	}
	return 0;
}