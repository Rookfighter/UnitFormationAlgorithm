#include "ufa/ui/DrawableUnit.hpp"
#include "ufa/general/Math.hpp"

#define CIRCLE_THICKNESS 0.1f
#define RECT_THICKNESS 0.1f
#define LINE_THICKNESS 0.05f
#define UNIT_COLOR sf::Color::Green
#define SELECTED_COLOR sf::Color::Red
#define TARGET_COLOR sf::Color::Blue

namespace ufa
{

	DrawableUnit::DrawableUnit(const std::shared_ptr<UnitController> &p_unitController)
	:selected_(false), unitController_(p_unitController)
	{	}

	DrawableUnit::~DrawableUnit()
	{	}
	
	void DrawableUnit::draw(sf::RenderTarget &p_renderTarget)
	{
		float midRadius = unitController_->getUnit()->radius / 8;
		float circleRadius = unitController_->getUnit()->radius - CIRCLE_THICKNESS;
		position_.x = unitController_->getUnit()->position.x;
		position_.y = unitController_->getUnit()->position.y;
		
		if(unitController_->getUnit()->moving) {
			sf::CircleShape targetCircle(midRadius);
			targetCircle.setFillColor(TARGET_COLOR);
			targetCircle.setPosition(unitController_->getUnit()->targetPosition.x - targetCircle.getRadius(), unitController_->getUnit()->targetPosition.y - targetCircle.getRadius());
			
			sf::Vector2f diff((unitController_->getUnit()->targetPosition - unitController_->getUnit()->position).length(),
							  LINE_THICKNESS);
			sf::RectangleShape targetLine(diff);
			targetLine.setPosition(position_);
			targetLine.rotate(radianToDegree(atan2(unitController_->getUnit()->targetPosition.y - unitController_->getUnit()->position.y,
												   unitController_->getUnit()->targetPosition.x - unitController_->getUnit()->position.x)));
			targetLine.setFillColor(TARGET_COLOR);
			
			p_renderTarget.draw(targetCircle);
			p_renderTarget.draw(targetLine);
		}
		
		sf::CircleShape mid(midRadius);
		mid.setFillColor(UNIT_COLOR);
		
		sf::CircleShape circle(circleRadius);
		circle.setFillColor(sf::Color::Transparent);
		circle.setOutlineThickness(CIRCLE_THICKNESS);
		circle.setOutlineColor(UNIT_COLOR);
		
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
			botRight.x += 2;
			botRight.y += 2;
			
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
	
	std::shared_ptr<UnitController>& DrawableUnit::getUnitController()
	{
		return unitController_;
	}
}

