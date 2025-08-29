cmake_minimum_required(VERSION 3.10)
project(csound-skeleton C)      # C++ = CXX

# Include custom functions
include("${CMAKE_CURRENT_SOURCE_DIR}/../cmake/CmakeFunctions.cmake")

# Look for custom find modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../cmake")

find_package(Csound6 REQUIRED)   # C++ = CsoundCXX

set(SOURCES
    src/main.c
    src/assets.c
)

if(WIN32)
    message(STATUS "Compiling for Windows")
    list(APPEND SOURCES src/os/windows.c)
elseif(APPLE)
    message(STATUS "Compiling for macOS")
    list(APPEND SOURCES src/os/apple.c)
else()
    message(STATUS "Compiling for Unix")
    list(APPEND SOURCES src/os/unix.c)
endif()

add_executable(csound-skeleton ${SOURCES})
target_link_libraries(csound-skeleton PRIVATE Csound::Csound6)
install(TARGETS csound-skeleton DESTINATION ${CMAKE_INSTALL_BINDIR})

# Copy static assets next to the EXE
add_custom_target(copy_assets ALL
    COMMAND ${CMAKE_COMMAND} -E make_directory assets
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/assets assets
    COMMENT "Copying assets"
)

add_dependencies(csound-skeleton copy_assets)

set(CMAKE_INSTALL_DATADIR "share/${PROJECT_NAME}")
set(PROJECT_ASSETS_PATH "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_DATADIR}")
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/assets/ DESTINATION ${PROJECT_ASSETS_PATH})

# Generate config.h file
configure_file(config.h.in ${CMAKE_BINARY_DIR}/config.h)
include_directories(${CMAKE_BINARY_DIR})

# On Windows copy the DLL next to the EXE
if(WIN32)
    zz_copy_runtime_libraries(csound-skeleton Csound::Csound6_CXX)
    zz_install_runtime_libraries(csound-skeleton Csound::Csound6_CXX)
endif()
