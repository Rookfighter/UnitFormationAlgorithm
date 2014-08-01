#include "ufa/ui/DrawableUnit.hpp"

#define CIRCLE_THICKNESS(sizefac) (sizefac / 30)
#define UNIT_COLOR sf::Color::Green

namespace ufa
{

	DrawableUnit::DrawableUnit(const std::shared_ptr<Unit> &p_unit)
	:unit_(p_unit)
	{	}

	DrawableUnit::~DrawableUnit()
	{	}

	void DrawableUnit::draw(DrawEvent &p_drawEvent)
	{
		int midRadius = (int) ((unit_->radius * p_drawEvent.sizeFactor) / 8);
		sf::CircleShape mid(midRadius);
		mid.setFillColor(UNIT_COLOR);
		
		int circleRadius = (int) ((unit_->radius * p_drawEvent.sizeFactor) - CIRCLE_THICKNESS(p_drawEvent.sizeFactor));
		sf::CircleShape circle(circleRadius);
		circle.setFillColor(sf::Color::Transparent);
		circle.setOutlineThickness(CIRCLE_THICKNESS(p_drawEvent.sizeFactor));
		circle.setOutlineColor(UNIT_COLOR);
		
		mid.setPosition(unit_->position.x * p_drawEvent.sizeFactor -  midRadius, unit_->position.y * p_drawEvent.sizeFactor - midRadius);
		circle.setPosition(unit_->position.x * p_drawEvent.sizeFactor - circleRadius, unit_->position.y * p_drawEvent.sizeFactor - circleRadius);
		
		p_drawEvent.renderTarget.draw(circle);
		p_drawEvent.renderTarget.draw(mid);
	}
}

