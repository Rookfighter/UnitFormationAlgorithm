#ifndef UFA_UNIT_HPP
#define UFA_UNIT_HPP

#include <deque>
#include "ufa/entities/Vec2.hpp"

namespace ufa
{
	class Unit
	{
	public:
		Vec2 position;
		float radius;
		Vec2 velocity;
		float maxVelocity;
		Vec2 targetPosition;
		bool moving;
		
		Unit();
		Unit(const Vec2 &p_position, const float p_radius);
		~Unit();

	};
}

#endif
