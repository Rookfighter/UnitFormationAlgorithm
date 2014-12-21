#include "logic/BlockFormationController.hpp"
#include "logic/BlockFormationShape.hpp"

namespace ufa
{

	BlockFormationController::BlockFormationController(const std::vector<std::shared_ptr<Unit>> &p_units)
	:FormationController(p_units, new BlockFormationShape())
	{
	}

	BlockFormationController::~BlockFormationController()
	{
		delete formationShape_;
	}
}
