#ifndef UFA_DRAWABLE_HPP
#define UFA_DRAWABLE_HPP

#include <SFML/Graphics.hpp>

namespace ufa
{
	class Drawable
	{
	public:
		Drawable(){ }
		virtual ~Drawable() { }
		
		virtual void draw(sf::RenderTarget &p_renderTarget) = 0;
	};

}

#endif // UFA_DRAWABLE_HPP
