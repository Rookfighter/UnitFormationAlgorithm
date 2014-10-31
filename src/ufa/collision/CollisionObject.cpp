#include "ufa/collision/CollisionObject.hpp"

namespace collision
{

	CollisionObject::CollisionObject()
	: gridTileSize_(1,1), innerRadius_(1), outerRadius_(1), userData_(NULL), next_(NULL), prev_(NULL)
	{
	}

	CollisionObject::~CollisionObject()
	{
	}
	
	void CollisionObject::setPosition(const Vec2f& p_position)
	{
		position_ = p_position;
	}
	
	void CollisionObject::setVelocity(const Vec2f& p_velocity)
	{
		velocity_ = p_velocity;
	}

	void CollisionObject::setInnerRadius(const float p_radius)
	{
		innerRadius_ = p_radius;
	}

	void CollisionObject::setOuterRadius(const float p_radius)
	{
		outerRadius_ = p_radius;
	}

	void CollisionObject::setUserData(void* p_userData)
	{
		userData_ = p_userData;
	}
	
	void CollisionObject::setGridTileSize(const Vec2f& p_size)
	{
		gridTileSize_ = p_size;
	}
	
	const Vec2f& CollisionObject::getPosition() const
	{
		return position_;
	}
	
	const Vec2f& CollisionObject::getVelocity() const
	{
		return velocity_;
	}
	
	float CollisionObject::getInnerRadius() const
	{
		return innerRadius_;
	}

	float CollisionObject::getOuterRadius() const
	{
		return outerRadius_;
	}

	void* CollisionObject::getUserData()
	{
		return userData_;
	}
	
	Vec2i CollisionObject::getGridPosition() const
	{
		Vec2i result;
		result.x = position_.x / gridTileSize_.x;
		result.y = position_.y / gridTileSize_.y;
		return result;
	}

}
