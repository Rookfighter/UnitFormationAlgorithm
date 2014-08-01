#ifndef UFA_DRAWABLE_UNIT_HPP
#define UFA_DRAWABLE_UNIT_HPP

#include <memory>
#include "ufa/ui/Drawable.hpp"
#include "ufa/entities/Unit.hpp"

namespace ufa
{
	class DrawableUnit: public Drawable
	{
	private:
		std::shared_ptr<Unit> unit_;
	public:
		bool selected_;
		DrawableUnit(const std::shared_ptr<Unit> &p_unit);
		~DrawableUnit();
		
		void draw(DrawEvent &p_drawEvent);
	};

}

#endif // UFA_DRAWABLE_UNIT_HPP
