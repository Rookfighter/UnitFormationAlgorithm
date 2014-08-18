#include "ufa/ui/DrawableUnit.hpp"

#define CIRCLE_THICKNESS 0.1f
#define RECT_THICKNESS 0.1f
#define UNIT_COLOR sf::Color::Green
#define SELECTED_COLOR sf::Color::Red

namespace ufa
{

	DrawableUnit::DrawableUnit(const std::shared_ptr<Unit> &p_unit)
	:selected_(false), unit_(p_unit)
	{	}

	DrawableUnit::~DrawableUnit()
	{	}
	
	void DrawableUnit::draw(sf::RenderTarget &p_renderTarget)
	{
		float midRadius = unit_->radius / 8;
		sf::CircleShape mid;
		mid.setRadius(midRadius);
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
			
			sf::Vector2i topLeft = p_renderTarget.mapCoordsToPixel(circle.getPosition());
			sf::Vector2i botRight= p_renderTarget.mapCoordsToPixel(sf::Vector2f(circle.getPosition().x + circle.getRadius() * 2, circle.getPosition().y + circle.getRadius() * 2));
			
			topLeft.x -= 1;
			topLeft.y -= 1;
			botRight.x += 1;
			botRight.y += 1;
			
			sf::Vector2f topLeftf = p_renderTarget.mapPixelToCoords(topLeft);
			sf::Vector2f botRightf = p_renderTarget.mapPixelToCoords(botRight);
			
			rect.setPosition(topLeftf);
			rect.setSize(sf::Vector2f(fabs(topLeftf.x - botRightf.x), fabs(topLeftf.y - botRightf.y)));
			
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

