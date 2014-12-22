include_directories("${CMAKE_SOURCE_DIR}/src" ${SFML_INCLUDE_DIR})
file(GLOB UFA_LIB_SRC
	"collision/*.cpp"
	"entities/*.cpp"
	"ui/*.cpp"
	"logic/*.cpp"
	"general/*.cpp"
	"app/*.cpp")

file(GLOB UFA_EXEC_SRC
    "main.cpp")

add_library(${UFA_LIBRARY} ${UFA_LIB_SRC})

add_executable(${UFA_EXEC} ${UFA_EXEC_SRC})
target_link_libraries(${UFA_EXEC} ${UFA_LIBRARY} ${SFML_LIBRARIES})
