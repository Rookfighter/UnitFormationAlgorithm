#ifndef UFA_FORMATION_PLACEMENT_HPP
#define UFA_FORMATION_PLACEMENT_HPP

#include "entities/Formation.hpp"

namespace ufa
{

	class FormationPlacement
	{
	public:
		FormationPlacement() { }
		virtual ~FormationPlacement() { }
		
		virtual void placeUnits(Formation &p_formation) = 0;

	};

}

#endif
