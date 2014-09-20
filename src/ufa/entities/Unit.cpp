#include "Unit.hpp"

namespace ufa
{
	Unit::Unit(const UnitType p_unitType,
			   const RangeType p_rangeType,
			   const float p_innerRadius, 
			   const float p_outerRadius,
			   const float p_maxVeloxity)
	:unitType(p_unitType), rangeType(p_rangeType), innerRadius(p_innerRadius),
	 outerRadius(p_outerRadius), maxVelocity(p_maxVeloxity), position(),
	 velocity(), targetPosition(), moving(false)
	{ }
	
	Unit::~Unit()
	{ }
	
	void Unit::moveToTarget(const Vec2 &p_target)
	{
		targetPosition = p_target;
		moving = true;
	}
}

