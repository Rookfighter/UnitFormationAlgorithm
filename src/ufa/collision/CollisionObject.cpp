#include <cassert>
#include "ufa/collision/CollisionObject.hpp"

namespace collision
{

	CollisionObject::CollisionObject()
	: tileSize_(1,1), radius_(1), userData_(NULL)
	{
	}

	CollisionObject::~CollisionObject()
	{
	}
	
	void CollisionObject::setPosition(const Vec2f& p_position)
	{
	    assert(p_position.x >= 0 && p_position.y >= 0);
		position_ = p_position;
	}
	
	void CollisionObject::setVelocity(const Vec2f& p_velocity)
	{
		velocity_ = p_velocity;
	}

	void CollisionObject::setRadius(const float p_radius)
	{
	    assert(p_radius > 0);
		radius_ = p_radius;
	}

	void CollisionObject::setUserData(void* p_userData)
	{
		userData_ = p_userData;
	}
	
	void CollisionObject::setGridTileSize(const Vec2f& p_size)
	{
	    assert(p_size.x > 0 && p_size.y > 0);
		tileSize_ = p_size;
	}
	
	const Vec2f& CollisionObject::getPosition() const
	{
		return position_;
	}
	
	const Vec2f& CollisionObject::getVelocity() const
	{
		return velocity_;
	}
	
	float CollisionObject::getRadius() const
	{
		return radius_;
	}

	void* CollisionObject::getUserData()
	{
		return userData_;
	}
	
	Vec2i CollisionObject::getGridPosition() const
	{
		Vec2i result;
		result.x = position_.x / tileSize_.x;
		result.y = position_.y / tileSize_.y;
		return result;
	}

	Circle CollisionObject::getCirlce() const
	{
	    return Circle(position_, radius_);
	}

}


