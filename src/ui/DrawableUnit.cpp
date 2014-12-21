#include "ui/DrawableUnit.hpp"
#include "general/Math.hpp"

#define CIRCLE_THICKNESS 0.1f
#define RECT_THICKNESS 0.1f
#define LINE_THICKNESS 0.05f
#define SELECTED_COLOR sf::Color::Red
#define TARGET_COLOR sf::Color::Blue

#define DEFAULT_UNIT_COLOR sf::Color::Magenta

namespace ufa
{

	DrawableUnit::DrawableUnit(const std::shared_ptr<UnitController> &p_unitController, const sf::Color p_unitcolor)
		:selected_(false), unitController_(p_unitController), unitColor_(p_unitcolor)
	{
		
	}

	DrawableUnit::~DrawableUnit()
	{	}

	void DrawableUnit::draw(sf::RenderTarget &p_renderTarget)
	{
		updatePosition();

		if(unitController_->getUnit()->moving)
			drawTarget(p_renderTarget);

		drawUnit(p_renderTarget);
	}

	void DrawableUnit::updatePosition()
	{
		position_.x = unitController_->getUnit()->position.x;
		position_.y = unitController_->getUnit()->position.y;
	}

	void DrawableUnit::drawTarget(sf::RenderTarget &p_renderTarget)
	{
		float midRadius = unitController_->getUnit()->outerRadius / 8;
		float circleRadius = unitController_->getUnit()->outerRadius - CIRCLE_THICKNESS;

		sf::CircleShape targetCircle(unitController_->getUnit()->outerRadius / 8);
		targetCircle.setFillColor(TARGET_COLOR);
		targetCircle.setPosition(unitController_->getUnit()->targetPosition.x - targetCircle.getRadius(),
		                         unitController_->getUnit()->targetPosition.y - targetCircle.getRadius());

		float lineLength = (unitController_->getUnit()->targetPosition - unitController_->getUnit()->position).length();
		sf::RectangleShape targetLine(sf::Vector2f(lineLength, LINE_THICKNESS));
		targetLine.setPosition(position_);
		float diffX = unitController_->getUnit()->targetPosition.x - unitController_->getUnit()->position.x;
		float diffY = unitController_->getUnit()->targetPosition.y - unitController_->getUnit()->position.y;
		targetLine.rotate(radianToDegree(atan2(diffY, diffX)));
		targetLine.setFillColor(TARGET_COLOR);

		p_renderTarget.draw(targetCircle);
		p_renderTarget.draw(targetLine);
	}

	void DrawableUnit::drawUnit(sf::RenderTarget &p_renderTarget)
	{
		float pointRadius = unitController_->getUnit()->outerRadius / 8;
		float circleRadius = unitController_->getUnit()->outerRadius - CIRCLE_THICKNESS;

		sf::CircleShape point(pointRadius);
		point.setFillColor(unitColor_);
		point.setPosition(position_.x -  pointRadius, position_.y - pointRadius);

		sf::CircleShape circle(circleRadius);
		circle.setFillColor(sf::Color::Transparent);
		circle.setOutlineThickness(CIRCLE_THICKNESS);
		circle.setOutlineColor(unitColor_);
		circle.setPosition(position_.x - circleRadius, position_.y - circleRadius);

		p_renderTarget.draw(circle);
		p_renderTarget.draw(point);

		if(selected_)
			drawSelection(circle.getPosition(), sf::Vector2f(circle.getRadius() * 2, circle.getRadius() * 2), p_renderTarget);
	}

	void DrawableUnit::drawSelection(const sf::Vector2f &p_position, const sf::Vector2f &p_size, sf::RenderTarget &p_renderTarget)
	{
		sf::RectangleShape rect;
		rect.setFillColor(sf::Color::Transparent);
		rect.setOutlineColor(SELECTED_COLOR);
		rect.setOutlineThickness(RECT_THICKNESS);

		sf::Vector2i topLeft = p_renderTarget.mapCoordsToPixel(p_position);
		sf::Vector2i botRight= p_renderTarget.mapCoordsToPixel(sf::Vector2f(p_position.x + p_size.x, p_position.y + p_size.y));

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
