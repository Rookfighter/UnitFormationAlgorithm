#include "entities/Formation.hpp"
#include "general/Math.hpp"

namespace ufa
{

	Formation::Formation()
		:center(), targetPosition(), moving(false), orientation(0), units(),
		 state(BROKEN)
	{
	}

	Formation::~Formation()
	{
	}

	bool Formation::reachedTarget(const float p_epsilon) const
	{
		return sameFloat(center.x, targetPosition.x, p_epsilon) &&
			   sameFloat(center.y, targetPosition.y, p_epsilon);
	}
	
}
