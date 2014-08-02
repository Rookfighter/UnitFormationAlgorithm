#ifndef UFA_MOUSE_BOX_HPP
#define UFA_MOUSE_BOX_HPP

#include "ufa/ui/Drawable.hpp"

namespace ufa
{
	/* This class represents a box which is can be drawn by the mouse. */
	class MouseBox: public Drawable
	{
	public:
		sf::Vector2f pointA;
		sf::Vector2f pointB;
		bool drawBox;
		
		MouseBox();
		~MouseBox();
		
		void draw(DrawEvent &p_drawEvent);
		sf::Vector2f getSize();
		sf::Vector2f getPosition();
		
	};

}

#endif // UFA_MOUSE_BOX_HPP
