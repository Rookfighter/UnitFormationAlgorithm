cmake_minimum_required(VERSION 2.8)
project(UnitFormationAlgorithm)

set(CMAKE_CXX_FLAGS "-std=c++11")

get_filename_component(SFML_ROOT "./lib/SFML-2.2" ABSOLUTE)
get_filename_component(CATCH_ROOT "./lib/Catch" ABSOLUTE)
get_filename_component(CDL_MODULES_PATH "./cmake-modules" ABSOLUTE) 
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CDL_MODULES_PATH})

find_package(SFML 2 COMPONENTS system window graphics audio network REQUIRED)
find_package(Catch)

add_subdirectory(src)
add_subdirectory(test)

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
	file(GLOB SFML_TO_COPY
		"${SFML_ROOT}/lib/libsfml-audio.so.*"
		"${SFML_ROOT}/lib/libsfml-system.so.*"
		"${SFML_ROOT}/lib/libsfml-network.so.*"
		"${SFML_ROOT}/lib/libsfml-graphics.so.*"
		"${SFML_ROOT}/lib/libsfml-window.so.*"
	)
endif( ${WIN32} )

foreach(TO_COPY ${SFML_TO_COPY})
	add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_if_different
			${TO_COPY}
			$<TARGET_FILE_DIR:${PROJECT_NAME}>)
endforeach(TO_COPY ${SFML_TO_COPY})

