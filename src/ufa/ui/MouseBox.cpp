#include "ufa/ui/MouseBox.hpp"

#define BOX_COLOR sf::Color::White
#define BOX_THICKNESS 1

namespace ufa
{
	MouseBox::MouseBox()
	:drawBox(false), pointA(0,0), pointB(0,0)
	{	}

	MouseBox::~MouseBox()
	{	}
	
	void MouseBox::draw(sf::RenderTarget &p_renderTarget)
	{
		if(drawBox) {
			sf::RectangleShape box;
			
			sf::Vector2f topLeftTmp = p_renderTarget.mapPixelToCoords(topLeft());
			sf::Vector2f botRightTmp = p_renderTarget.mapPixelToCoords(botRight());
			sf::Vector2f size(abs(topLeftTmp.x - botRightTmp.x), abs(topLeftTmp.y - botRightTmp.y));
			
			box.setSize(size);
			box.setPosition(topLeftTmp);
			box.setFillColor(sf::Color::Transparent);
			box.setOutlineColor(BOX_COLOR);
			box.setOutlineThickness(BOX_THICKNESS);
			
			p_renderTarget.draw(box);
		}
	}
	
	sf::Vector2i MouseBox::topLeft()
	{
		sf::Vector2i result;
		if(pointA.x < pointB.x)
			result.x = pointA.x;
		else
			result.x = pointB.x;
		
		if(pointA.y < pointB.y)
			result.y = pointA.y;
		else
			result.y = pointB.y;
			
		return result;
	}
	
	sf::Vector2i MouseBox::botRight()
	{
		sf::Vector2i result;
		if(pointA.x > pointB.x)
			result.x = pointA.x;
		else
			result.x = pointB.x;
		
		if(pointA.y > pointB.y)
			result.y = pointA.y;
		else
			result.y = pointB.y;
			
		return result;
	}
	
	sf::Vector2i MouseBox::size()
	{
		sf::Vector2i topLeftTmp = topLeft();
		sf::Vector2i botRightTmp = botRight();
		return sf::Vector2i(abs(topLeftTmp.x - botRightTmp.x), abs(topLeftTmp.y - botRightTmp.y));
	}
		
	sf::Vector2f MouseBox::topLeft(sf::RenderTarget &p_renderTarget)
	{
		return p_renderTarget.mapPixelToCoords(topLeft());
	}
	
	sf::Vector2f MouseBox::botRight(sf::RenderTarget &p_renderTarget)
	{
		return p_renderTarget.mapPixelToCoords(botRight());
	}
	
	sf::Vector2f MouseBox::size(sf::RenderTarget &p_renderTarget)
	{
		sf::Vector2f topLeftTmp = topLeft(p_renderTarget);
		sf::Vector2f botRightTmp = botRight(p_renderTarget);
		return sf::Vector2f(fabs(topLeftTmp.x - botRightTmp.x), fabs(topLeftTmp.y - botRightTmp.y));
	}

}

