#include "general/Math.hpp"

namespace ufa
{
	bool sameFloat(const float a, const float b, const float epsilon)
	{
		return fabs(a - b) < epsilon;
	}
	
	float usecToFps(const int p_usec)
	{
		return ((float) USEC_PER_SEC) / ((float) p_usec);
	}
	
	int fpsToUsec(const float p_fps)
	{
		return  ((float) USEC_PER_SEC) / p_fps;
	}
	
	float usecToSec(const int p_usec)
	{
		return ((float) p_usec) / ((float) USEC_PER_SEC);
	}
	
	int secToUsec(const float p_sec)
	{
		return p_sec * USEC_PER_SEC;
	}
	
	float radianToDegree(const float p_radian)
	{
		return p_radian * 180.0f / M_PI;
	}
	
	float degreeToRadian(const float p_degree)
	{
		return p_degree * M_PI / 180.0f;
	}
	
	Vec2 rotateVector(const Vec2 &p_vector, const float p_radian)
	{
		Vec2 result;
		
		float cs = cos(p_radian);
		float sn = sin(p_radian);
		
		result.x = p_vector.x * cs - p_vector.y * sn;
		result.y = p_vector.x * sn + p_vector.y * cs;
		
		return result;
	}
}