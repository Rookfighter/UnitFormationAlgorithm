#include <climits>
#include <cstdlib>
#include <ctime>
#include "ufa/general/Random.hpp"

namespace ufa
{

	static bool rand_initialized = false;
	
	Random::Random()
	{
		if(!rand_initialized) {
			std::srand(static_cast<unsigned> (std::time(NULL)));
			rand_initialized = true;
		}
	}

	Random::~Random()
	{
	}
	
	int Random::nextInt()
	{
		return std::rand();
	}
	
	int Random::nextInt(const int p_range)
	{
		return nextInt() % p_range;
	}
	
	float Random::nextFloat()
	{
		return static_cast<float> (std::rand()) / static_cast<float> (RAND_MAX);
	}
	
	bool Random::nextBool()
	{
		return nextInt(2) == 0;
	}


}
