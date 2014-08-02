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
	public:
		DrawableUnit(const std::shared_ptr<Unit> &p_unit);
		~DrawableUnit();
		
		void draw(DrawEvent &p_drawEvent);
	};

}

#endif // UFA_DRAWABLE_UNIT_HPP
