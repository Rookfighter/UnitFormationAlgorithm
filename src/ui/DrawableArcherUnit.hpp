#ifndef UFA_DRAWABLE_ARCHER_UNIT_HPP
#define UFA_DRAWABLE_ARCHER_UNIT_HPP

#include "ui/DrawableUnit.hpp"

namespace ufa
{

	class DrawableArcherUnit : public ufa::DrawableUnit
	{
	public:
		DrawableArcherUnit(const std::shared_ptr<UnitController> &p_unitController);
		~DrawableArcherUnit();

	};

}

#endif
