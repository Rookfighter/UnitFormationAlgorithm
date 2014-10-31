#ifndef COLLISION_VEC2I_HPP
#define COLLISION_VEC2I_HPP

#include <string>

namespace collision
{
	/* This class implements a 2D vector. It provides mathematical operators for adding,
	 * subtracting and scaling. */
	class Vec2i
	{
	public:
		int x;
		int y;
	
		Vec2i(): x(0), y(0) { }
		Vec2i(float p_x, float p_y): x(p_x), y(p_y) { }
		~Vec2i() { }
		
		void set(const float p_x, const float p_y);
		float lengthSQ() const;
		float length() const;
		Vec2i perpendicular() const;
		
		Vec2i& operator+=(Vec2i const& p_vec);
		Vec2i& operator-=(Vec2i const& p_vec);
		Vec2i& operator*=(const float p_factor);
		Vec2i& operator/=(const float p_divisor);
		
		std::string str() const;
	};
	
	const Vec2i operator+(Vec2i const& p_vec1, Vec2i const& p_Vec2i);
	const Vec2i operator-(Vec2i const& p_vec1, Vec2i const& p_Vec2i);
	const Vec2i operator*(Vec2i const& p_vec, const float p_factor);
	const Vec2i operator*(const float p_factor, Vec2i const& p_vec);
	const Vec2i operator/(Vec2i const& p_vec, const float p_divisor);
	bool operator==(Vec2i const& p_vec1, Vec2i const& p_Vec2i);
	bool operator!=(Vec2i const& p_vec1, Vec2i const& p_Vec2i);
}

#endif
