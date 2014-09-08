#include "ufa/ui/DrawableMeleeUnit.hpp"

#define MELEE_UNIT_COLOR sf::Color::Green

namespace ufa
{

	DrawableMeleeUnit::DrawableMeleeUnit(const std::shared_ptr<UnitController> &p_unitController)
		:DrawableUnit(p_unitController, MELEE_UNIT_COLOR)
	{

	}

	DrawableMeleeUnit::~DrawableMeleeUnit()
	{

	}


}
