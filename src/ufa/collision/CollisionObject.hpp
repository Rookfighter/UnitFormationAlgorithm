#ifndef COLLISION_COLLISION_OBJECT_HPP
#define COLLISION_COLLISION_OBJECT_HPP

#include "ufa/collision/Vec2f.hpp"
#include "ufa/collision/Vec2i.hpp"

namespace collision
{
	class CollisionObject
	{
		friend class World;
	private:
		Vec2f position_;
		Vec2f velocity_;
		Vec2f gridTileSize_;
		
		float innerRadius_;
		float outerRadius_;
		
		void *userData_;
		
		CollisionObject *next_;
		CollisionObject *prev_;
		
		CollisionObject();
	public:
		~CollisionObject();
		
		void setPosition(const Vec2f &p_position);
		void setVelocity(const Vec2f &p_velocity);
		void setInnerRadius(const float p_radius);
		void setOuterRadius(const float p_radius);
		void setUserData(void *p_userData);
		void setGridTileSize(const Vec2f &p_size);
		
		const Vec2f& getPosition() const;
		const Vec2f& getVelocity() const;
		float getInnerRadius() const;
		float getOuterRadius() const;
		void* getUserData();
		Vec2i getGridPosition() const;
		
	};

}

#endif
