#ifndef UFA_MATH_HPP
#define UFA_MATH_HPP

#include <cmath>
#include "ufa/entities/Vec2.hpp"

#ifndef M_PI
#define M_PI (3.14159265359)
#endif

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

#define MSEC_PER_SEC 1000
#define USEC_PER_SEC 1000000

namespace ufa
{
	bool sameFloat(const float a, const float b, const float epsilon);
	float usecToFps(const int p_usec);
	int fpsToUsec(const float p_fps);
	
	float usecToSec(const int p_usec);
	int secToUsec(const float p_sec);
	
	float radianToDegree(const float p_radian);
	float degreeToRadian(const float p_degree);
	
	Vec2 rotateVector(const Vec2 &p_vector, const float p_radian);
}

#endif