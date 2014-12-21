#ifndef UFA_BLOCK_FORMATION_CONTROLLER_HPP
#define UFA_BLOCK_FORMATION_CONTROLLER_HPP

#include "logic/FormationController.hpp"

namespace ufa
{

	class BlockFormationController : public ufa::FormationController
	{
	public:
		BlockFormationController(const std::vector<std::shared_ptr<Unit>> &p_units);
		~BlockFormationController();
	};

}

#endif
