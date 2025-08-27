cmake_minimum_required(VERSION 3.10)
project(tuning_fork CXX)

# Include custom functions
include("${CMAKE_CURRENT_SOURCE_DIR}/../cmake/CmakeFunctions.cmake")

# Look for custom find modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../cmake")
find_package(Csound6_CXX REQUIRED)

add_executable(tuning-fork
    src/main.cpp
)

target_link_libraries(tuning-fork PRIVATE Csound::Csound6_CXX)
install(TARGETS tuning-fork DESTINATION ${CMAKE_INSTALL_BINDIR})

# Copy static assets next to the EXE
add_custom_command(TARGET tuning-fork POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory assets
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/assets assets
)

set(CMAKE_INSTALL_DATADIR "share/${PROJECT_NAME}")
set(PROJECT_ASSETS_PATH "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_DATADIR}/assets")
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/assets/ DESTINATION ${PROJECT_ASSETS_PATH})

# Generate config.h file
configure_file(config.h.in ${CMAKE_BINARY_DIR}/config.h)
include_directories(${CMAKE_BINARY_DIR})

# On Windows copy the DLL next to the EXE
if(WIN32)
    zz_copy_runtime_libraries(tuning-fork Csound::Csound6_CXX)
    zz_install_runtime_libraries(tuning-fork Csound::Csound6_CXX)
endif()
