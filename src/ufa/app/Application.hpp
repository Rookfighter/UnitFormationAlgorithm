#ifndef UFA_APPLICATION_HPP
#define UFA_APPLICATION_HPP

#include "ufa/app/GameFactory.hpp"

namespace ufa
{

	class Application
	{
	private:
		GameFactory gameFactory_;
		float fps_;
		
		void generateUnits();
	public:
		Application(const float p_fps);
		~Application();
		
		void run();
	};

}

#endif
