#ifndef COLLISION_COLLISION_TILE_HPP
#define COLLISION_COLLISION_TILE_HPP

#include <vector>
#include "collision/Vec2i.hpp"
#include "collision/Vec2f.hpp"
#include "collision/Rectangle.hpp"

namespace collision
{
	class CollisionTile
	{
	private:
		static const unsigned int GRANULARITY = 4;
		
		Vec2i gridPosition_;
		Vec2f tileSize_;
		
		bool isObstacle_;
		std::vector<std::vector<bool>> fineGrainedArea_;
		
		void *userData_;
		
		void initFineGrainedArea();
	public:
		CollisionTile(const Vec2i& p_position);
		~CollisionTile();
		
		void setIsObstalce(const bool p_isObstacle);
		void setIsFineGrained(const bool p_isFineGrained);
		void setFineGrainedTile(const int x, const int y, const bool p_tileIsObstalce);
		void setTileSize(const Vec2f &p_size);
		void setUserData(void *p_userData);
		
		const Vec2i& getGridPosition() const;
		Vec2f getPosition() const;
		const Vec2f& getTileSize() const;
		bool isObstacle() const;
		bool isFineGrained() const;
		bool getFineGrainedTile(const int x, const int y) const;
		void getFineGrainedRects(std::vector<Rectangle> &p_tileRects) const;
		unsigned int getGranularity() const;
		void* getUserData();
		Rectangle getRect() const;
	};

}

#endif
