#ifndef UFA_FORMATION_SHAPE_HPP
#define UFA_FORMATION_SHAPE_HPP

#include "ufa/entities/Formation.hpp"

namespace ufa
{

	class FormationShape
	{
	public:
		FormationShape() { }
		virtual ~FormationShape() { }
		
		virtual void calcFormationPositions(Formation &p_formation) = 0;

	};

}

#endif
