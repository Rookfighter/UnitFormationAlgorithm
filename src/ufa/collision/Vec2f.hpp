#ifndef COLLISION_VEC2F_HPP
#define COLLISION_VEC2F_HPP

#include <string>

namespace collision
{
	/* This class implements a 2D vector. It provides mathematical operators for adding,
	 * subtracting and scaling. */
	class Vec2f
	{
	public:
		float x;
		float y;
	
		Vec2f(): x(0), y(0) { }
		Vec2f(float p_x, float p_y): x(p_x), y(p_y) { }
		~Vec2f() { }
		
		void set(const float p_x, const float p_y);
		float lengthSQ() const;
		float length() const;
		void normalize();
		void invert();
		Vec2f perpendicular() const;
		
		Vec2f& operator+=(Vec2f const& p_vec);
		Vec2f& operator-=(Vec2f const& p_vec);
		Vec2f& operator*=(const float p_factor);
		Vec2f& operator/=(const float p_divisor);
		
		std::string str() const;
	};
	
	const Vec2f operator+(Vec2f const& p_vec1, Vec2f const& p_vec2);
	const Vec2f operator-(Vec2f const& p_vec1, Vec2f const& p_vec2);
	const Vec2f operator*(Vec2f const& p_vec, const float p_factor);
	const Vec2f operator*(const float p_factor, Vec2f const& p_vec);
	float operator*(Vec2f const& p_vec1, Vec2f const& p_vec2);
	const Vec2f operator/(Vec2f const& p_vec, const float p_divisor);
	bool operator==(Vec2f const& p_vec1, Vec2f const& p_vec2);
	bool operator!=(Vec2f const& p_vec1, Vec2f const& p_vec2);
}

#endif
