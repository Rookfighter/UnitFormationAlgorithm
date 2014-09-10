#include "ufa/logic/BlockFormationController.hpp"
#include "ufa/general/Math.hpp"

namespace ufa
{

	BlockFormationController::BlockFormationController(const std::vector<std::shared_ptr<Unit>> &p_units)
	:FormationController(p_units), rows_(0), rowLength_(4)
	{
	}

	BlockFormationController::~BlockFormationController()
	{
	}

	void BlockFormationController::calcUnitPositions()
	{
		rows_ = formation_.units.size() / rowLength_;
		
		float maxRadius = getMaxRadius();
		
		float x = ( ((float) rows_) / 2) * maxRadius;
		float y = ( ((float) rowLength_) / 2) * maxRadius;
		
		for(int i = 0; i < rows_; ++i) {
			for(int j = 0; j < rowLength_; ++j) {
				formation_.units[i * rowLength_ + j].formationPosition.x = x - i * maxRadius * 2;
				formation_.units[i * rowLength_ + j].formationPosition.y = y - j * maxRadius * 2;
			}
		}
	}
	
	float BlockFormationController::getMaxRadius()
	{
		float result = 0;
		for(int i = 0; i < formation_.units.size(); ++i)
			result = MAX(result, formation_.units[i].unit->outerRadius);
		return result;
	}

}
