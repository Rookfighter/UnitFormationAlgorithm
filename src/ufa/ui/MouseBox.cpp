#include "ufa/ui/MouseBox.hpp"

#define BOX_COLOR sf::Color::White
#define BOX_THICKNESS 1

namespace ufa
{
	MouseBox::MouseBox()
	:drawBox(false), pointA(0,0), pointB(100,100)
	{	}

	MouseBox::~MouseBox()
	{	}
	
	void MouseBox::draw(DrawEvent &p_drawEvent)
	{
		if(drawBox) {
			sf::RectangleShape box;
			box.setSize(getSize());
			box.setPosition(getPosition());
			box.setFillColor(sf::Color::Transparent);
			box.setOutlineColor(BOX_COLOR);
			box.setOutlineThickness(BOX_THICKNESS);
			
			p_drawEvent.renderTarget.draw(box);
		}
	}
	
	sf::Vector2f MouseBox::getSize()
	{
		return sf::Vector2f(fabs(pointA.x - pointB.x), fabs(pointA.y - pointB.y));
	}
	
	sf::Vector2f MouseBox::getPosition()
	{
		sf::Vector2f topLeft;
		
		if(pointA.x < pointB.x)
			topLeft.x = pointA.x;
		else
			topLeft.x = pointB.x;
		
		if(pointA.y < pointB.y)
			topLeft.y = pointA.y;
		else
			topLeft.y = pointB.y;
			
		return topLeft;
	}


}

