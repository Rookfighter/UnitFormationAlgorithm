#ifndef UFA_VEC2_HPP
#define UFA_VEC2_HPP

#include <string>

namespace ufa
{
	/* This class implements a 2D vector. It provides mathematical operators for adding,
	 * subtracting and scaling. */
	class Vec2
	{
	public:
		float x;
		float y;
	
		Vec2(): x(0), y(0) { }
		Vec2(float p_x, float p_y): x(p_x), y(p_y) { }
		~Vec2() { }
		
		void set(const float p_x, const float p_y);
		float lengthSQ() const;
		float length() const;
		Vec2 perpendicular() const;
		
		Vec2& operator+=(Vec2 const& p_vec);
		Vec2& operator-=(Vec2 const& p_vec);
		Vec2& operator*=(const float p_factor);
		Vec2& operator/=(const float p_divisor);
		
		std::string str() const;
	};
	
	const Vec2 operator+(Vec2 const& p_vec1, Vec2 const& p_vec2);
	const Vec2 operator-(Vec2 const& p_vec1, Vec2 const& p_vec2);
	const Vec2 operator*(Vec2 const& p_vec, const float p_factor);
	const Vec2 operator*(const float p_factor, Vec2 const& p_vec);
	const Vec2 operator/(Vec2 const& p_vec, const float p_divisor);
	bool operator==(Vec2 const& p_vec1, Vec2 const& p_vec2);
	bool operator!=(Vec2 const& p_vec1, Vec2 const& p_vec2);
}

#endif
