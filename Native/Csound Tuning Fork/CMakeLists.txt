cmake_minimum_required(VERSION 3.10)
project(csound-tuning-fork CXX)

# Include custom functions
include("${CMAKE_CURRENT_SOURCE_DIR}/../cmake/CmakeFunctions.cmake")

# Look for custom find modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../cmake")
find_package(Csound6_CXX REQUIRED)

# See: https://wiki.libsdl.org/SDL2/README-cmake
find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)
find_package(SDL2 REQUIRED CONFIG COMPONENTS SDL2main)
    
set(SOURCES
    src/main.cpp
    src/assets.cpp
)

if(WIN32)
    message(STATUS "Compiling for Windows")
    list(APPEND SOURCES src/os/windows.cpp)
elseif(APPLE)
    message(STATUS "Compiling for macOS")
    list(APPEND SOURCES src/os/apple.cpp)
else()
    message(STATUS "Compiling for Unix")
    list(APPEND SOURCES src/os/unix.cpp)
endif()

if(UNIX)
    include(GNUInstallDirs)
else()
    set(${CMAKE_INSTALL_LIBDIR} "lib")
    set(${CMAKE_INSTALL_DATADIR} "share")
    set(${CMAKE_INSTALL_INCLUDEDIR} "include")
    set(${CMAKE_INSTALL_BINDIR} "bin")
endif()

add_executable(csound-tuning-fork ${SOURCES})
install(TARGETS csound-tuning-fork DESTINATION ${CMAKE_INSTALL_BINDIR})

target_link_libraries(csound-tuning-fork PRIVATE Csound::Csound6_CXX)

if(TARGET SDL2::SDL2main)
    # Only available/required for Windows GUI applications
    # MUST be added before SDL2::SDL2 (or SDL2::SDL2-static)
    target_link_libraries(csound-tuning-fork PRIVATE SDL2::SDL2main)
endif()

target_link_libraries(csound-tuning-fork PRIVATE SDL2::SDL2)

# Copy static assets next to the EXE
add_custom_target(copy_assets ALL
    COMMAND ${CMAKE_COMMAND} -E make_directory assets
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/assets assets
    COMMENT "Copying assets"
)

add_dependencies(csound-tuning-fork copy_assets)

set(CMAKE_INSTALL_DATADIR "share/${PROJECT_NAME}")
set(PROJECT_ASSETS_PATH "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_DATADIR}")
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/assets/ DESTINATION ${PROJECT_ASSETS_PATH})

# Generate config.hpp file
configure_file(config.hpp.in ${CMAKE_BINARY_DIR}/config.hpp)
include_directories(${CMAKE_BINARY_DIR})

# On Windows copy the DLL next to the EXE
option(BUNDLE_LIBRARIES "Bundle external libraries with the program (recommended e.g. on Windows)" OFF)
if(BUNDLE_LIBRARIES)
    zz_copy_runtime_libraries(csound-tuning-fork Csound::Csound6_CXX)
    zz_install_runtime_libraries(csound-tuning-fork Csound::Csound6_CXX)

    zz_copy_runtime_libraries(csound-tuning-fork SDL2::SDL2)
    zz_install_runtime_libraries(csound-tuning-fork SDL2::SDL2)
    
    if(TARGET SDL2::SDL2main)
        zz_copy_runtime_libraries(csound-tuning-fork SDL2::SDL2main)
        zz_install_runtime_libraries(csound-tuning-fork SDL2::SDL2main)
    endif()
endif()
