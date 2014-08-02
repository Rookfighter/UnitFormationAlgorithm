#include "ufa/ui/DrawableUnit.hpp"

#define CIRCLE_THICKNESS(sizefac) (sizefac / 30)
#define RECT_THICKNESS(sizefac) (sizefac / 30)
#define UNIT_COLOR sf::Color::Green
#define SELECTED_COLOR sf::Color::Red

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
		
		position.x = unit_->position.x * p_drawEvent.sizeFactor;
		position.y = unit_->position.y * p_drawEvent.sizeFactor;
		mid.setPosition(position.x -  midRadius, position.y - midRadius);
		circle.setPosition(position.x - circleRadius, position.y - circleRadius);
		
		p_drawEvent.renderTarget.draw(circle);
		p_drawEvent.renderTarget.draw(mid);
		
		if(selected) {
			//draw a rect around the unit to show that it is selected
			sf::RectangleShape rect;
			rect.setFillColor(sf::Color::Transparent);
			rect.setOutlineColor(SELECTED_COLOR);
			rect.setOutlineThickness(RECT_THICKNESS(p_drawEvent.sizeFactor));
			rect.setPosition(circle.getPosition().x - 1, circle.getPosition().y - 1);
			rect.setSize(sf::Vector2f((circle.getRadius() * 2) + 2, (circle.getRadius() * 2) + 2));
			
			p_drawEvent.renderTarget.draw(rect);
		}
	}
}

