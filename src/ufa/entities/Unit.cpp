#include "Unit.hpp"

#define DEF_MAX_VELOCITY 5.0f

namespace ufa
{
	Unit::Unit()
	:Unit(Vec2(), 1.0f)
	{ }
	
	Unit::Unit(const Vec2 &p_position, const float p_radius)
	:position(p_position), radius(p_radius), velocity(), targetPosition(), moving(false), maxVelocity(DEF_MAX_VELOCITY)
	{ } 
	
	Unit::~Unit()
	{ }
}

