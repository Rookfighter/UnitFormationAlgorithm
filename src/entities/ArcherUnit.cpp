#include "entities/ArcherUnit.hpp"

#define UNIT_TYPE ARCHER
#define RANGE_TYPE RANGED
#define INNER_RADIUS 0.3f
#define OUTER_RADIUS 1.0f
#define MAX_VELOCITY 5.0f

namespace ufa
{

	ArcherUnit::ArcherUnit()
	:Unit(UNIT_TYPE, RANGE_TYPE, INNER_RADIUS, OUTER_RADIUS, MAX_VELOCITY)
	{
	}

	ArcherUnit::~ArcherUnit()
	{
	}


}
