#ifndef UFA_RANDOM_HPP
#define UFA_RANDOM_HPP

namespace ufa
{
	class Random
	{
	public:
		Random();
		~Random();
		
		int nextInt();
		int nextInt(const int p_range);
		
		float nextFloat();
		
		bool nextBool();
		
		

	};

}

#endif
