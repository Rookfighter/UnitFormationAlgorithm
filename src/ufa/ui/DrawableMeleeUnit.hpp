#ifndef UFA_DRAWABLE_MELEE_UNIT_HPP
#define UFA_DRAWABLE_MELEE_UNIT_HPP

#include "ufa/ui/DrawableUnit.hpp"

namespace ufa
{

	class DrawableMeleeUnit : public DrawableUnit
	{
	public:
		DrawableMeleeUnit(const std::shared_ptr<UnitController> &p_unitController);
		~DrawableMeleeUnit();

	};

}

#endif
