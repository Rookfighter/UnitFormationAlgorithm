if( ${CATCH_FOUND} )

    set(UFA_TEST_EXEC TestUFA)
    
    include_directories("${CMAKE_SOURCE_DIR}/src" ${SFML_INCLUDE_DIR} ${CATCH_INCLUDE_DIR})
    file(GLOB UFA_TEST_SRC
        "main.cpp"
        "collision/*.cpp")
        
    add_executable(${UFA_TEST_EXEC} ${UFA_TEST_SRC})
    target_link_libraries(${UFA_TEST_EXEC} ${UFA_LIBRARY} ${SFML_LIBRARIES})
    
endif( ${CATCH_FOUND} )
