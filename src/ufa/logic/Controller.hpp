#ifndef UFA_CONTROLLER_HPP
#define UFA_CONTROLLER_HPP

namespace ufa
{
	class Controller
	{
	public:
		Controller() { }
		virtual ~Controller() { }
			
		virtual void step(const unsigned int p_usec) = 0;
	};

}

#endif
