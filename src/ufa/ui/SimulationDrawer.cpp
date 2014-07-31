#include "ufa/ui/SimulationDrawer.hpp"
#include <iostream>
#define SIZE_FACTOR 30
#define CIRCLE_THICKNESS 3
#define UNIT_COLOR sf::Color::Cyan

namespace ufa
{

	SimulationDrawer::SimulationDrawer(const std::shared_ptr<World> &p_world)
	: world_(p_world)
	{	}

	SimulationDrawer::~SimulationDrawer()
	{	}

	void SimulationDrawer::drawSimulation(sf::RenderTarget &p_renderTarget)
	{
		std::list<std::shared_ptr<Unit>>::iterator it;
		for(it = world_->units.begin(); it != world_->units.end(); ++it)
			drawUnit(p_renderTarget, *it);
	}
	
	void SimulationDrawer::drawUnit(sf::RenderTarget &p_renderTarget, const std::shared_ptr<Unit> p_unit)
	{
		
		int midRadius = (int) ((p_unit->radius * SIZE_FACTOR) / 8);
		sf::CircleShape mid(midRadius);
		mid.setFillColor(UNIT_COLOR);
		
		int circleRadius = (int) ((p_unit->radius * SIZE_FACTOR) - CIRCLE_THICKNESS);
		sf::CircleShape circle(circleRadius);
		circle.setFillColor(sf::Color::Transparent);
		circle.setOutlineThickness(CIRCLE_THICKNESS);
		circle.setOutlineColor(UNIT_COLOR);
		
		mid.setPosition(p_unit->position.x * SIZE_FACTOR -  midRadius, p_unit->position.y * SIZE_FACTOR - midRadius);
		circle.setPosition(p_unit->position.x * SIZE_FACTOR - circleRadius, p_unit->position.y * SIZE_FACTOR - circleRadius);
		
		p_renderTarget.draw(circle);
		p_renderTarget.draw(mid);
	}
}

