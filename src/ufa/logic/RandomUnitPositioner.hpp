#ifndef UFA_RANDOM_UNIT_POSITIONER_HPP
#define UFA_RANDOM_UNIT_POSITIONER_HPP

#include "ufa/entities/World.hpp"
#include "ufa/entities/Unit.hpp"
#include "ufa/general/Random.hpp"

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
