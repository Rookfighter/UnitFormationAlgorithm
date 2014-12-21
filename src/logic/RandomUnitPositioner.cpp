#include "logic/RandomUnitPositioner.hpp"

namespace ufa
{

	RandomUnitPositioner::RandomUnitPositioner()
	{
	}

	RandomUnitPositioner::~RandomUnitPositioner()
	{
	}
	
	void RandomUnitPositioner::inArea(std::shared_ptr<Unit> p_unit, const Vec2 &p_mid, const float p_radius)
	{
		float xOffset = random_.nextFloat() * p_radius;
		float yOffset = random_.nextFloat() * p_radius;
		
		if(random_.nextBool())
			xOffset = -xOffset;
		if(random_.nextBool())
			yOffset = -yOffset;
			
		p_unit->position.set(p_mid.x + xOffset, p_mid.y + yOffset);
	}


}
