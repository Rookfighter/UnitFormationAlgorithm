#ifndef UFA_BLOCK_FORMATION_SHAPE_HPP
#define UFA_BLOCK_FORMATION_SHAPE_HPP

#include "ufa/logic/FormationShape.hpp"
#include "ufa/logic/FormationPlacement.hpp"

namespace ufa
{

	class BlockFormationShape : public FormationShape
	{
	private:
		Formation *currentFormation_;
		FormationPlacement *formationPlacement_;
		int rows_;
		int rowLength_;
		
		float getMaxRadius();
	public:
		BlockFormationShape();
		~BlockFormationShape();

		void calcFormationPositions(Formation& p_formation);
	};

}

#endif
