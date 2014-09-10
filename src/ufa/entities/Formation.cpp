#include "ufa/entities/Formation.hpp"

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


}
