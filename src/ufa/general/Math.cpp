#include "ufa/general/Math.hpp"

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
}