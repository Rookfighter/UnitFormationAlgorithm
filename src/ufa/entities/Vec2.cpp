#include <cmath>
#include <sstream>
#include "ufa/entities/Vec2.hpp"

namespace ufa
{
	void Vec2::set(const float p_x, const float p_y)
	{
		x = p_x;
		y = p_y;
	}
	
	float Vec2::lengthSQ() const
	{
		return x * x + y * y;
	}
	
	float Vec2::length() const
	{
		return sqrt(lengthSQ());
	}
	
	Vec2 Vec2::perpendicular() const
	{
		return Vec2(-y, x);
	}
	
	Vec2& Vec2::operator+=(Vec2 const& p_vec)
	{
		x += p_vec.x;
		y += p_vec.y;
		
		return *this;
	}
	
	Vec2& Vec2::operator-=(Vec2 const& p_vec)
	{
		x -= p_vec.x;
		y -= p_vec.y;
		
		return *this;
	}
	
	Vec2& Vec2::operator*=(const float p_factor)
	{
		x *= p_factor;
		y *= p_factor;
		
		return *this;
	}
	
	Vec2& Vec2::operator/=(const float p_divisor)
	{
		x /= p_divisor;
		y /= p_divisor;
		
		return *this;
	}
	
	std::string Vec2::str() const
	{
		std::stringstream ss;
		ss.precision(2);
		ss << "(" << x << ";" << y << ")";
		return ss.str();
	}
	
	const Vec2 operator+(Vec2 const& p_vec1, Vec2 const& p_vec2)
	{
		Vec2 result(p_vec1);
		result += p_vec2;
		
		return result;
	}
	
	const Vec2 operator-(Vec2 const& p_vec1, Vec2 const& p_vec2)
	{
		Vec2 result(p_vec1);
		result -= p_vec2;
		
		return result;
	}
	
	const Vec2 operator*(Vec2 const& p_vec, const float p_factor)
	{
		Vec2 result(p_vec);
		result *= p_factor;
		
		return result;
	}
	
	const Vec2 operator*(const float p_factor, Vec2 const& p_vec)
	{
		return p_vec * p_factor;
	}
	
	const Vec2 operator/(Vec2 const& p_vec, const float p_divisor)
	{
		Vec2 result(p_vec);
		result /= p_divisor;
		
		return result;
	}
	
	bool operator==(Vec2 const& p_vec1, Vec2 const& p_vec2)
	{
		return p_vec1.x == p_vec2.x && p_vec1.y == p_vec2.y;
	}
	
	bool operator!=(Vec2 const& p_vec1, Vec2 const& p_vec2)
	{
		return !(p_vec1 == p_vec2);
	}
}

