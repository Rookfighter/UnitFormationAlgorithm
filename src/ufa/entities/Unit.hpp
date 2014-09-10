#ifndef UFA_UNIT_HPP
#define UFA_UNIT_HPP

#include "ufa/entities/Vec2.hpp"

#define RANGE_TYPE_CLOSE 0
#define RANGE_TYPE_RANGED 1

namespace ufa
{
	enum RangeType {CLOSE = 0, RANGED};
	enum UnitType {MELEE, ARCHER};
	
	/* Unit is a simple entity that contains all information about
	 * a Unit like its position, velocity, radius, etc. */
	class Unit
	{
	public:
		Vec2 position;
		float innerRadius;
		float outerRadius;
		
		Vec2 velocity;
		float maxVelocity;
		
		const UnitType unitType;
		RangeType rangeType;
		
		Vec2 targetPosition;
		bool moving;
		
		Unit(const UnitType p_unitType,
			 const RangeType p_rangeType,
			 const float p_innerRadius, 
			 const float p_outerRadius,
			 const float p_maxVeloxity);
		virtual ~Unit();

	};
}

#endif
