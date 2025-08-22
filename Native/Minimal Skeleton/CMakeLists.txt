cmake_minimum_required(VERSION 3.10)
project(csound_skeleton C)

# Look for custom find modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../cmake")

find_package(Csound REQUIRED)

set(CSOUND_SKELETON_SOURCES
    src/main.c
)

add_executable(csound_skeleton ${CSOUND_SKELETON_SOURCES})
target_link_libraries(csound_skeleton PRIVATE Csound::Csound)

# On Windows copy the DLL next to the EXE
if(WIN32)
    add_custom_command(TARGET csound_skeleton POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
	$<TARGET_FILE:Csound::Csound> $<TARGET_FILE_DIR:csound_example>
    )
endif()
