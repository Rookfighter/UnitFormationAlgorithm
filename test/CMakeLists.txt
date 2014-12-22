if( ${CATCH_FOUND} )
    include_directories("${CMAKE_SOURCE_DIR}/src" ${SFML_INCLUDE_DIR} ${CATCH_INCLUDE_DIR})
    file(GLOB UFA_TEST_SRC
        "main.cpp"
        "collision/*.cpp")
    
    message(STATUS "ufa lib: ${UFA_LIBRARY}")
    add_executable(${UFA_TEST_EXEC} ${UFA_TEST_SRC})
    target_link_libraries(${UFA_TEST_EXEC} ${UFA_LIBRARY} ${SFML_LIBRARIES})
else( ${CATCH_FOUND} )
    message(STATUS "  No Tests will be built")
endif( ${CATCH_FOUND} )
