#ifndef UFA_DRAWABLE_UNIT_HPP
#define UFA_DRAWABLE_UNIT_HPP

#include <memory>
#include "ufa/ui/Drawable.hpp"
#include "ufa/entities/Unit.hpp"

namespace ufa
{
	/* DrawableUnit represents the visualization of an Unit. */
	class DrawableUnit: public Drawable
	{
	private:
		std::shared_ptr<Unit> unit_;
		sf::Vector2f position_;
		bool selected_;
	public:
		DrawableUnit(const std::shared_ptr<Unit> &p_unit);
		~DrawableUnit();
		
		void draw(sf::RenderTarget &p_renderTarget);
		void select(const bool p_selected);
		bool isSelected();
		
		sf::Vector2f position();
	};

}

#endif
