#ifndef UFA_BLOCK_FORMATION_CONTROLLER_HPP
#define UFA_BLOCK_FORMATION_CONTROLLER_HPP

#include "ufa/logic/FormationController.hpp"

namespace ufa
{

	class BlockFormationController : public ufa::FormationController
	{
	private:
		int rows_;
		int rowLength_;
		
		float getMaxRadius();
	protected:
		virtual void calcUnitPositions();
	public:
		BlockFormationController(const std::vector<std::shared_ptr<Unit>> &p_units);
		~BlockFormationController();
	};

}

#endif
