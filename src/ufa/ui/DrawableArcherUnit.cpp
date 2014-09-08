#include "ufa/ui/DrawableArcherUnit.hpp"

#define ARCHER_UNIT_COLOR sf::Color::Yellow

namespace ufa
{

	DrawableArcherUnit::DrawableArcherUnit(const std::shared_ptr<UnitController> &p_unitController)
		:DrawableUnit(p_unitController, ARCHER_UNIT_COLOR)
	{
	}

	DrawableArcherUnit::~DrawableArcherUnit()
	{
	}


}
