function (add_death_test NAME)
    # Avoid building this target normally.
    set_target_properties(${NAME} PROPERTIES
        EXCLUDE_FROM_ALL TRUE
        EXCLUDE_FROM_DEFAULT_BUILD TRUE
    )
    # Add the test.
    add_test(NAME ${NAME}
        COMMAND ${CMAKE_COMMAND} --build . --target ${NAME} --config $<CONFIGURATION>
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )
    # Expect this test to fail.
    set_tests_properties(${NAME} PROPERTIES
        WILL_FAIL TRUE
    )
endfunction()
