#include <memory>
#include "ufa/general/Logging.hpp"
#include "ufa/logic/SimulationController.hpp"
#include "ufa/logic/UnitController.hpp"
#include "ufa/entities/World.hpp"
#include "ufa/ui/DrawWindow.hpp"
#include "ufa/ui/MouseEventHandler.hpp"
#include "ufa/ui/WindowEventHandler.hpp"
#include "ufa/ui/DrawableUnit.hpp"
#include "ufa/general/Math.hpp"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define FPS 30

std::shared_ptr<ufa::World> world(new ufa::World());
std::shared_ptr<ufa::UnitController> unitController(new ufa::UnitController(world));
std::shared_ptr<ufa::SimulationController> simulationController(new ufa::SimulationController());
std::shared_ptr<ufa::DrawWindow> window(new ufa::DrawWindow(SCREEN_WIDTH, SCREEN_HEIGHT, world));
std::shared_ptr<ufa::Unit> unit(new ufa::Unit());
std::shared_ptr<ufa::DrawableUnit> drawUnit(new ufa::DrawableUnit(unit));

static void init()
{
	unit->position.set(10,10);
	unit->radius = 1;
	
	world->units.push_back(unit);
	window->getDrawer().drawObjects.push_back(drawUnit);
	simulationController->addController(unitController);
	window->addEventHandler(std::shared_ptr<ufa::WindowEventHandler>(new ufa::WindowEventHandler(window)));
	window->addEventHandler(std::shared_ptr<ufa::MouseEventHandler>(new ufa::MouseEventHandler(window)));
}

static void run()
{
	sf::Time loopTime = sf::microseconds(FPS_TO_USEC(FPS));
	sf::Time elapsed;
	sf::Clock clock;
	clock.restart();
	while(window->getRenderWindow().isOpen()) {
		simulationController->step(loopTime.asMicroseconds());
		window->redraw();
		window->processPendingEvents();
		
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