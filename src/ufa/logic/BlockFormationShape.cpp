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

		rows_ = sqrt(((float)currentFormation_->units.size()) / ROW_LENGTH_RATIO);
		if(rows_ <= 0)
			rows_ = 1;
		rowLength_ = ROW_LENGTH_RATIO * rows_;

		while(rowLength_ * rows_ < currentFormation_->units.size())
			rowLength_++;

		float maxRadius = getMaxRadius();

		float x = (((float) rows_) / 2) * maxRadius;

		for(int i = 0; i < rows_; ++i) {
			for(int j = 0; j < rowLength_; ++j) {
				if(i * rowLength_ + j < currentFormation_->units.size()) {
					currentFormation_->units[i * rowLength_ + j].position.x = x - i * maxRadius * 2;
					currentFormation_->units[i * rowLength_ + j].position.y = pow(-1, j) * ((j / 2) * maxRadius * 2 + maxRadius);
				}
			}
		}

		//formationPlacement_->placeUnits(p_formation);
	}

	float BlockFormationShape::getMaxRadius()
	{
		float result = 0;
		for(int i = 0; i < currentFormation_->units.size(); ++i)
			result = MAX(result, currentFormation_->units[i].unit->outerRadius);
		return result;
	}

}
