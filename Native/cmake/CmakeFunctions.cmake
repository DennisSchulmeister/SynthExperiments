#
# Function to copy runtime libraries after the build (for local testing)
#
function(zz_copy_runtime_libraries target library)
    # Retrieve the libraries from INTERFACE_LINK_LIBRARIES
    get_target_property(LINKED_LIBS ${library} INTERFACE_LINK_LIBRARIES)

    # Copy the libraries in INTERFACE_LINK_LIBRARIES
    if(LINKED_LIBS)
        foreach(lib ${LINKED_LIBS})
            add_custom_command(TARGET ${target} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                ${lib} $<TARGET_FILE_DIR:${target}>
            )
        endforeach()
    endif()

    # Copy the main library (IMPORTED_LOCATION)
    get_target_property(IMPORTED_LIB ${library} IMPORTED_LOCATION)

    if(IMPORTED_LIB)
        add_custom_command(TARGET ${target} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy
            ${IMPORTED_LIB} $<TARGET_FILE_DIR:${target}>
        )
    endif()
endfunction()

#
# Function to install runtime libraries (to create a self-contained installation package)
#
function(zz_install_runtime_libraries target library)
    # Retrieve the libraries from INTERFACE_LINK_LIBRARIES
    get_target_property(LINKED_LIBS ${library} INTERFACE_LINK_LIBRARIES)

    # Install the libraries from INTERFACE_LINK_LIBRARIES
    if(LINKED_LIBS)
        foreach(lib ${LINKED_LIBS})
            # Install the library to a destination directory (e.g., lib)
            install(FILES ${lib} DESTINATION ${CMAKE_INSTALL_LIBDIR})
        endforeach()
    endif()

    # Install the main library (IMPORTED_LOCATION)
    get_target_property(IMPORTED_LIB ${library} IMPORTED_LOCATION)

    if(IMPORTED_LIB)
        # Install the imported library to a destination directory (e.g., lib)
        install(FILES ${IMPORTED_LIB} DESTINATION ${CMAKE_INSTALL_LIBDIR})
    endif()
endfunction()
