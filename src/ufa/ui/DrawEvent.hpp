#ifndef UFA_DRAW_EVENT_HPP
#define UFA_DRAW_EVENT_HPP

#include <SFML/Graphics.hpp>

namespace ufa
{
	class DrawEvent
	{
	public:
		sf::RenderTarget &renderTarget;
		unsigned int sizeFactor;
		
		DrawEvent(sf::RenderTarget &p_renderTarget);
		~DrawEvent();

	};

}

#endif // UFA_DRAW_EVENT_HPP
