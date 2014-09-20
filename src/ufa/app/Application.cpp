#include "ufa/app/Application.hpp"
#include "ufa/logic/RandomUnitPositioner.hpp"
#include "ufa/general/Logging.hpp"
#include "ufa/general/Math.hpp"

#define UNIT_COUNT 64
#define APP_NAME "Unit Formation"

namespace ufa
{
	Application::Application(const float p_fps)
		:gameFactory_(), fps_(p_fps)
	{
		sf::View view = gameFactory_.getRenderWindow().getDefaultView();
		view.zoom(0.05);
		view.setCenter(0, 0);
		gameFactory_.getRenderWindow().setView(view);
		gameFactory_.getRenderWindow().setTitle(APP_NAME);
		
		gameFactory_.createMouseEventHandler();
		gameFactory_.createWindowEventHandler();

		generateUnits();
	}
	
	void Application::generateUnits()
	{
		RandomUnitPositioner positioner;
		for(int i = 0; i < UNIT_COUNT; ++i) {
			CreatedUnit result;
			if(i < UNIT_COUNT / 2)
				result = gameFactory_.createMeleeUnit();
			else
				result = gameFactory_.createRangedUnit();
			
			positioner.inArea(result.unit, Vec2(0,0), 10);
		}
	}

	Application::~Application()
	{
	}

	void Application::run()
	{
		sf::Time loopTime = sf::microseconds(fpsToUsec(fps_));
		sf::Time elapsed;
		sf::Clock clock;
		clock.restart();
		while(gameFactory_.getRenderWindow().isOpen()) {
			gameFactory_.getSimulationController().step(loopTime.asMicroseconds());
			gameFactory_.getGameDrawer().redraw();
			gameFactory_.getEventManager().processPendingEvents();

			elapsed = clock.getElapsedTime();
			if(loopTime > elapsed)
				sf::sleep(loopTime - elapsed);
			else
				PRINT_WARN("Gameloop timed out.");
			clock.restart();
		}
	}


}
