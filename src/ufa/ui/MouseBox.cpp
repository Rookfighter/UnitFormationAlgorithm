#include "ufa/ui/MouseBox.hpp"

#define BOX_COLOR sf::Color::White
#define BOX_THICKNESS 1

namespace ufa
{
	MouseBox::MouseBox()
	:drawBox(false), topLeft(0,0), size(100,100)
	{	}

	MouseBox::~MouseBox()
	{	}
	
	void MouseBox::draw(DrawEvent &p_drawEvent)
	{
		if(drawBox) {
			sf::RectangleShape box;
			box.setSize(size);
			box.setPosition(topLeft);
			box.setFillColor(sf::Color::Transparent);
			box.setOutlineColor(BOX_COLOR);
			box.setOutlineThickness(BOX_THICKNESS);
			
			p_drawEvent.renderTarget.draw(box);
		}
	}


}

