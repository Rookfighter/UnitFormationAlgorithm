#ifndef UFA_RANDOM_UNIT_POSITIONER_HPP
#define UFA_RANDOM_UNIT_POSITIONER_HPP

#include "entities/World.hpp"
#include "entities/Unit.hpp"
#include "general/Random.hpp"

namespace ufa
{

	class RandomUnitPositioner
	{
	private:
		Random random_;
	public:
		RandomUnitPositioner();
		~RandomUnitPositioner();
		
		void inArea(std::shared_ptr<Unit> p_unit, const Vec2 &p_mid, const float p_radius);
	};

}

#endif
