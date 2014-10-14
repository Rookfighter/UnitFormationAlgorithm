cmake_minimum_required(VERSION 2.8)
project(UnitFormationAlgorithm)

set(CMAKE_CXX_FLAGS "-std=c++11")

get_filename_component(SFML_ROOT "./lib/SFML-2.1" ABSOLUTE)
get_filename_component(CDL_MODULES_PATH "./cmake-modules" ABSOLUTE) 

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CDL_MODULES_PATH})

find_package(SFML 2 COMPONENTS system window graphics audio network REQUIRED)

include_directories("src" ${SFML_INCLUDE_DIR})
file(GLOB UFA_SRC
	"src/ufa/main.cpp"
	"src/ufa/entities/*.cpp"
	"src/ufa/ui/*.cpp"
	"src/ufa/logic/*.cpp"
	"src/ufa/general/*.cpp"
	"src/ufa/app/*.cpp")

add_executable(${PROJECT_NAME} ${UFA_SRC})
target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})

if( ${WIN32} )
	set(SFML_TO_COPY
		"${SFML_ROOT}/bin/libsndfile-1.dll"
		"${SFML_ROOT}/bin/openal32.dll"
		"${SFML_ROOT}/bin/sfml-audio-2.dll"
		"${SFML_ROOT}/bin/sfml-system-2.dll"
		"${SFML_ROOT}/bin/sfml-network-2.dll"
		"${SFML_ROOT}/bin/sfml-graphics-2.dll"
		"${SFML_ROOT}/bin/sfml-window-2.dll"
	)
else( ${WIN32} )
	set(SFML_TO_COPY
		"${SFML_ROOT}/lib/libsfml-audio.so.2"
		"${SFML_ROOT}/lib/libsfml-system.so.2"
		"${SFML_ROOT}/lib/libsfml-network.so.2"
		"${SFML_ROOT}/lib/libsfml-graphics.so.2"
		"${SFML_ROOT}/lib/libsfml-window.so.2"
	)
endif( ${WIN32} )

foreach(TO_COPY ${SFML_TO_COPY})
	add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_if_different
			${TO_COPY}
			$<TARGET_FILE_DIR:${PROJECT_NAME}>)
endforeach(TO_COPY ${SFML_TO_COPY})

