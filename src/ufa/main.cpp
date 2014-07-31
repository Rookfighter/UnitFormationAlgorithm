#include <memory>
#include <iostream>
#include "ufa/logic/SimulationController.hpp"
#include "ufa/logic/UnitController.hpp"
#include "ufa/entities/World.hpp"
#include "ufa/ui/DrawWindow.hpp"
#include "ufa/ui/MouseEventHandler.hpp"
#include "ufa/ui/WindowEventHandler.hpp"
#include "ufa/general/Math.hpp"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define FPS 30

std::shared_ptr<ufa::World> world(new ufa::World());
std::shared_ptr<ufa::UnitController> unitController(new ufa::UnitController(world));
std::shared_ptr<ufa::SimulationController> simulationController(new ufa::SimulationController());
std::shared_ptr<ufa::DrawWindow> window(new ufa::DrawWindow(SCREEN_WIDTH, SCREEN_HEIGHT, world));


static void init()
{
	world->units.push_back(std::shared_ptr<ufa::Unit>(new ufa::Unit()));
	world->units.front()->position.set(10,10);
	world->units.front()->radius = 1;
	simulationController->addController(unitController);
	window->addEventHandler(std::shared_ptr<ufa::WindowEventHandler>(new ufa::WindowEventHandler(window->getRenderWindow())));
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
			std::cout << "Timed out." << std::endl;
		clock.restart();
	}
}

int main()
{
	try {
		init();
		run();
	} catch(std::exception &e) {
		std::cout << "Catched exception: " << e.what() << std::endl;
	} catch(...) {
		std::cout << "Catched anything." << std::endl;
	}
	return 0;
}