#include <cmath>
#include <sstream>
#include "ufa/collision/Vec2f.hpp"

namespace collision
{
	void Vec2f::set(const float p_x, const float p_y)
	{
		x = p_x;
		y = p_y;
	}
	
	float Vec2f::lengthSQ() const
	{
		return x * x + y * y;
	}
	
	float Vec2f::length() const
	{
		return sqrt(lengthSQ());
	}
	
	void Vec2f::normalize()
	{
	    float len = length();
	    x /= len;
	    y /= len;
	}

	void Vec2f::invert()
	{
	    x = -x;
	    y = -y;
	}

	Vec2f Vec2f::perpendicular() const
	{
		return Vec2f(-y, x);
	}
	
	Vec2f& Vec2f::operator+=(Vec2f const& p_vec)
	{
		x += p_vec.x;
		y += p_vec.y;
		
		return *this;
	}
	
	Vec2f& Vec2f::operator-=(Vec2f const& p_vec)
	{
		x -= p_vec.x;
		y -= p_vec.y;
		
		return *this;
	}
	
	Vec2f& Vec2f::operator*=(const float p_factor)
	{
		x *= p_factor;
		y *= p_factor;
		
		return *this;
	}

	Vec2f& Vec2f::operator/=(const float p_divisor)
	{
		x /= p_divisor;
		y /= p_divisor;
		
		return *this;
	}
	
	std::string Vec2f::str() const
	{
		std::stringstream ss;
		ss.precision(2);
		ss << "(" << x << ";" << y << ")";
		return ss.str();
	}
	
	const Vec2f operator+(Vec2f const& p_vec1, Vec2f const& p_Vec2f)
	{
		Vec2f result(p_vec1);
		result += p_Vec2f;
		
		return result;
	}
	
	const Vec2f operator-(Vec2f const& p_vec1, Vec2f const& p_Vec2f)
	{
		Vec2f result(p_vec1);
		result -= p_Vec2f;
		
		return result;
	}
	
	const Vec2f operator*(Vec2f const& p_vec, const float p_factor)
	{
		Vec2f result(p_vec);
		result *= p_factor;
		
		return result;
	}
	
	const Vec2f operator*(const float p_factor, Vec2f const& p_vec)
	{
		return p_vec * p_factor;
	}
	
	float operator*(Vec2f const& p_vec1, Vec2f const& p_vec2)
	{
	    return p_vec1.x * p_vec2.x + p_vec1.y * p_vec2.y;
	}

	const Vec2f operator/(Vec2f const& p_vec, const float p_divisor)
	{
		Vec2f result(p_vec);
		result /= p_divisor;
		
		return result;
	}
	
	bool operator==(Vec2f const& p_vec1, Vec2f const& p_Vec2f)
	{
		return p_vec1.x == p_Vec2f.x && p_vec1.y == p_Vec2f.y;
	}
	
	bool operator!=(Vec2f const& p_vec1, Vec2f const& p_Vec2f)
	{
		return !(p_vec1 == p_Vec2f);
	}
}

