cmake_minimum_required(VERSION 2.8)
project(UnitFormationAlgorithm)

set(UFA_LIBRARY "ufa")
set(UFA_EXEC "UnitFormationAlgorithm")
set(UFA_TEST_EXEC "TestUFA")

set(CMAKE_CXX_FLAGS "-std=c++11")

get_filename_component(SFML_ROOT "./lib/SFML-2.2" ABSOLUTE)
get_filename_component(CATCH_ROOT "./lib/Catch" ABSOLUTE)
get_filename_component(CDL_MODULES_PATH "./cmake-modules" ABSOLUTE) 
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CDL_MODULES_PATH})

find_package(SFML 2 COMPONENTS system window graphics audio network REQUIRED)
find_package(Catch)

add_subdirectory(src)
add_subdirectory(test)

add_custom_target(test COMMAND ${UFA_TEST_EXEC} DEPENDS ${UFA_TEST_EXEC})