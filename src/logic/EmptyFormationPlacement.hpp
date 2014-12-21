#ifndef UFA_EMPTY_FORMATION_PLACEMENT_HPP
#define UFA_EMPTY_FORMATION_PLACEMENT_HPP

#include "logic/FormationPlacement.hpp"

namespace ufa
{

	class EmptyFormationPlacement : public FormationPlacement
	{
	public:
		EmptyFormationPlacement();
		~EmptyFormationPlacement();

		void placeUnits(Formation& p_formation);
	};

}

#endif
