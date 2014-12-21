#ifndef UFA_LOGGING_HPP
#define UFA_LOGGING_HPP

#include <cstdio>

#define PRINT_INFO(msg, ...) printf("[INFO] " msg "\n", ##__VA_ARGS__)
#define PRINT_WARN(msg, ...) fprintf(stderr, "[WARN] " msg "\n", ##__VA_ARGS__)
#define PRINT_ERROR(msg, ...) fprintf(stderr, "[ERROR] " msg "\n", ##__VA_ARGS__)

namespace ufa
{
	
}

#endif