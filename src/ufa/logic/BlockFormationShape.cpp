#include "ufa/logic/BlockFormationShape.hpp"
#include "ufa/logic/GaleShapleyAlgorithm.hpp"
#include "ufa/general/Math.hpp"

#define ROW_LENGTH_RATIO (2.0f)

namespace ufa
{

	BlockFormationShape::BlockFormationShape()
	:rowLength_(4), formationPlacement_(new GaleShapleyAlgorithm())
	{
	}

	BlockFormationShape::~BlockFormationShape()
	{
		delete formationPlacement_;
	}

	void BlockFormationShape::calcFormationPositions(Formation& p_formation)
	{
		currentFormation_ = &p_formation;
		
		rowLength_ = sqrt(ROW_LENGTH_RATIO * currentFormation_->units.size());
		rows_ = rowLength_ / ROW_LENGTH_RATIO;
		
		float maxRadius = getMaxRadius();
		
		float x = ( ((float) rows_) / 2) * maxRadius;
		float y = ( ((float) rowLength_) / 2) * maxRadius;
		
		for(int i = 0; i < rows_; ++i) {
			for(int j = 0; j < rowLength_; ++j) {
				if((i + 1) * (j + 1) < currentFormation_->units.size())
				currentFormation_->units[i * rowLength_ + j].position.x = x - i * maxRadius * 2;
				currentFormation_->units[i * rowLength_ + j].position.y = y - j * maxRadius * 2;
			}
		}
		
		formationPlacement_->placeUnits(p_formation);
	}
	
	float BlockFormationShape::getMaxRadius()
	{
		float result = 0;
		for(int i = 0; i < currentFormation_->units.size(); ++i)
			result = MAX(result, currentFormation_->units[i].unit->outerRadius);
		return result;
	}

}
