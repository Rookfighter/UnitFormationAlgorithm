#include "ufa/entities/RangedUnit.hpp"

#define UNIT_TYPE RANGED
#define RANGE_TYPE RANGE_TYPE_RANGED
#define INNER_RADIUS 0.3f
#define OUTER_RADIUS 1.0f
#define MAX_VELOCITY 5.0f

namespace ufa
{

	RangedUnit::RangedUnit()
	:Unit(UNIT_TYPE, RANGE_TYPE, INNER_RADIUS, OUTER_RADIUS, MAX_VELOCITY)
	{
	}

	RangedUnit::~RangedUnit()
	{
	}


}
