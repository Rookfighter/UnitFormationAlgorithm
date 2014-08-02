#ifndef UFA_DRAWABLE_HPP
#define UFA_DRAWABLE_HPP

#include <SFML/Graphics.hpp>
#include "ufa/ui/DrawEvent.hpp"

namespace ufa
{
	class Drawable
	{
	public:
		sf::Vector2f position;
		bool selected;
		
		Drawable(): selected(false) { }
		virtual ~Drawable() { }
		
		virtual void draw(DrawEvent &p_drawEvent) = 0;
	};

}

#endif // UFA_DRAWABLE_HPP
