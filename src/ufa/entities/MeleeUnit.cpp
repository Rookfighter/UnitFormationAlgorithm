#include "ufa/entities/MeleeUnit.hpp"

#define UNIT_TYPE MELEE
#define RANGE_TYPE RANGE_TYPE_CLOSE
#define INNER_RADIUS 0.3f
#define OUTER_RADIUS 1.0f
#define MAX_VELOCITY 5.0f

namespace ufa
{

	MeleeUnit::MeleeUnit()
	:Unit(UNIT_TYPE, RANGE_TYPE, INNER_RADIUS, OUTER_RADIUS, MAX_VELOCITY)
	{
		
	}

	MeleeUnit::~MeleeUnit()
	{
		
	}


}
