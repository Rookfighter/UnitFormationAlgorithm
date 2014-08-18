#include "ufa/ui/DrawableUnit.hpp"

#define CIRCLE_THICKNESS 0.5f
#define RECT_THICKNESS 0.5f
#define UNIT_COLOR sf::Color::Green
#define SELECTED_COLOR sf::Color::Red

namespace ufa
{

	DrawableUnit::DrawableUnit(const std::shared_ptr<Unit> &p_unit)
	:unit_(p_unit)
	{	}

	DrawableUnit::~DrawableUnit()
	{	}
	
	void DrawableUnit::draw(sf::RenderTarget &p_renderTarget)
	{
		float midRadius = unit_->radius / 8;
		sf::CircleShape mid(midRadius);
		mid.setFillColor(UNIT_COLOR);
		
		float circleRadius = unit_->radius - CIRCLE_THICKNESS;
		sf::CircleShape circle(circleRadius);
		circle.setFillColor(sf::Color::Transparent);
		circle.setOutlineThickness(CIRCLE_THICKNESS);
		circle.setOutlineColor(UNIT_COLOR);
		
		position_.x = unit_->position.x;
		position_.y = unit_->position.y;
		mid.setPosition(position_.x -  midRadius, position_.y - midRadius);
		circle.setPosition(position_.x - circleRadius, position_.y - circleRadius);
		
		p_renderTarget.draw(circle);
		p_renderTarget.draw(mid);
		
		if(selected_) {
			//draw a rect around the unit to show that it is selected
			sf::RectangleShape rect;
			rect.setFillColor(sf::Color::Transparent);
			rect.setOutlineColor(SELECTED_COLOR);
			rect.setOutlineThickness(RECT_THICKNESS);
			rect.setPosition(circle.getPosition().x - 1, circle.getPosition().y - 1);
			rect.setSize(sf::Vector2f((circle.getRadius() * 2) + 2, (circle.getRadius() * 2) + 2));
			
			p_renderTarget.draw(rect);
		}
	}
	
	void DrawableUnit::select(const bool p_selected)
	{
		selected_ = p_selected;
	}
	
	bool DrawableUnit::isSelected()
	{
		return selected_;
	}
		
	sf::Vector2f DrawableUnit::position()
	{
		return position_;
	}
}

