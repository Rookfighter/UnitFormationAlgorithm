#include "ufa/app/Application.hpp"
#include "ufa/general/Logging.hpp"

#define FPS 60

int main()
{
	try {
		ufa::Application app(FPS);
		app.run();
	} catch(std::exception &e) {
		PRINT_ERROR("Catched exception: %s.", e.what());
	} catch(...) {
		PRINT_ERROR("Catched anything.");
	}
	return 0;
}