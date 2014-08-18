#ifndef UFA_MOUSE_BOX_HPP
#define UFA_MOUSE_BOX_HPP

#include "ufa/ui/Drawable.hpp"

namespace ufa
{
	/* This class represents a box which is can be drawn by the mouse. */
	class MouseBox: public Drawable
	{
	public:
		sf::Vector2i pointA;
		sf::Vector2i pointB;
		bool drawBox;
		
		MouseBox();
		~MouseBox();
		
		void draw(sf::RenderTarget &p_renderTarget);
		
		sf::Vector2i topLeft();
		sf::Vector2i botRight();
		sf::Vector2i size();
		
		sf::Vector2f topLeft(sf::RenderTarget &p_renderTarget);
		sf::Vector2f botRight(sf::RenderTarget &p_renderTarget);
		sf::Vector2f size(sf::RenderTarget &p_renderTarget);
	};

}

#endif // UFA_MOUSE_BOX_HPP
