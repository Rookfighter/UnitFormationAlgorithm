#include "ufa/logic/BlockFormationController.hpp"
#include "ufa/logic/BlockFormationShape.hpp"
#include "ufa/logic/EmptyFormationPlacement.hpp"

namespace ufa
{

	BlockFormationController::BlockFormationController(const std::vector<std::shared_ptr<Unit>> &p_units)
	:FormationController(p_units, new BlockFormationShape(), new EmptyFormationPlacement())
	{
	}

	BlockFormationController::~BlockFormationController()
	{
		delete formationShape_;
		delete formationPlacement_;
	}
}
