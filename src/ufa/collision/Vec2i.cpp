#include <cmath>
#include <sstream>
#include "ufa/collision/Vec2i.hpp"

namespace collision
{
	void Vec2i::set(const float p_x, const float p_y)
	{
		x = p_x;
		y = p_y;
	}
	
	float Vec2i::lengthSQ() const
	{
		return x * x + y * y;
	}
	
	float Vec2i::length() const
	{
		return sqrt(lengthSQ());
	}
	
	Vec2i Vec2i::perpendicular() const
	{
		return Vec2i(-y, x);
	}
	
	Vec2i& Vec2i::operator+=(Vec2i const& p_vec)
	{
		x += p_vec.x;
		y += p_vec.y;
		
		return *this;
	}
	
	Vec2i& Vec2i::operator-=(Vec2i const& p_vec)
	{
		x -= p_vec.x;
		y -= p_vec.y;
		
		return *this;
	}
	
	Vec2i& Vec2i::operator*=(const float p_factor)
	{
		x *= p_factor;
		y *= p_factor;
		
		return *this;
	}
	
	Vec2i& Vec2i::operator/=(const float p_divisor)
	{
		x /= p_divisor;
		y /= p_divisor;
		
		return *this;
	}
	
	std::string Vec2i::str() const
	{
		std::stringstream ss;
		ss.precision(2);
		ss << "(" << x << ";" << y << ")";
		return ss.str();
	}
	
	const Vec2i operator+(Vec2i const& p_vec1, Vec2i const& p_Vec2i)
	{
		Vec2i result(p_vec1);
		result += p_Vec2i;
		
		return result;
	}
	
	const Vec2i operator-(Vec2i const& p_vec1, Vec2i const& p_Vec2i)
	{
		Vec2i result(p_vec1);
		result -= p_Vec2i;
		
		return result;
	}
	
	const Vec2i operator*(Vec2i const& p_vec, const float p_factor)
	{
		Vec2i result(p_vec);
		result *= p_factor;
		
		return result;
	}
	
	const Vec2i operator*(const float p_factor, Vec2i const& p_vec)
	{
		return p_vec * p_factor;
	}
	
	const Vec2i operator/(Vec2i const& p_vec, const float p_divisor)
	{
		Vec2i result(p_vec);
		result /= p_divisor;
		
		return result;
	}
	
	bool operator==(Vec2i const& p_vec1, Vec2i const& p_Vec2i)
	{
		return p_vec1.x == p_Vec2i.x && p_vec1.y == p_Vec2i.y;
	}
	
	bool operator!=(Vec2i const& p_vec1, Vec2i const& p_Vec2i)
	{
		return !(p_vec1 == p_Vec2i);
	}
}

