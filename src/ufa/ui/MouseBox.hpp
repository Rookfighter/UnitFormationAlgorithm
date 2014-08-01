#ifndef UFA_MOUSE_BOX_HPP
#define UFA_MOUSE_BOX_HPP

#include "ufa/ui/Drawable.hpp"

namespace ufa
{
	class MouseBox: public Drawable
	{
	public:
		sf::Vector2f topLeft;
		sf::Vector2f size;
		bool drawBox;
		
		MouseBox();
		~MouseBox();
		
		void draw(DrawEvent &p_drawEvent);
	};

}

#endif // UFA_MOUSE_BOX_HPP
