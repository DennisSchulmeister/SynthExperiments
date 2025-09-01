cmake_minimum_required(VERSION 3.25)
project(csound-tuning-fork CXX)

# Include custom functions
include("${CMAKE_CURRENT_SOURCE_DIR}/../cmake/CmakeFunctions.cmake")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../cmake")

# Find external libraries
find_package(Csound6_CXX REQUIRED)
find_package(ImGui_SDL2 REQUIRED)
#find_package(ImGuiKnobs REQUIRED)
#find_package(ImGuiToggle REQUIRED)

# Build our application
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

set(SOURCES
    src/assets.cpp
    src/main.cpp
    src/ui.cpp

    # Could be replaced for other platforms, if SDL shall be avoided
    src/imgui_backend/sdl2.cpp
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
    set(${CMAKE_INSTALL_INCLUDEDIR} "include")
    set(${CMAKE_INSTALL_BINDIR} "bin")
endif()

set(CMAKE_INSTALL_DATADIR "share/${PROJECT_NAME}")
set(PROJECT_ASSETS_PATH "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_DATADIR}")

add_executable(csound-tuning-fork ${SOURCES})
install(TARGETS csound-tuning-fork DESTINATION ${CMAKE_INSTALL_BINDIR})
target_link_libraries(csound-tuning-fork PRIVATE Csound::Csound6_CXX)
target_link_libraries(csound-tuning-fork PRIVATE ImGui_SDL2)
#target_link_libraries(csound-tuning-fork PRIVATE ImGuiKnobs)
#target_link_libraries(csound-tuning-fork PRIVATE ImGuiToggle)

# Generate config.hpp file
configure_file(config.hpp.in ${CMAKE_BINARY_DIR}/config.hpp)
include_directories(${CMAKE_BINARY_DIR})

# Copy static assets next to the EXE
add_custom_target(copy_assets ALL
    COMMAND ${CMAKE_COMMAND} -E make_directory assets
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/assets assets
    COMMENT "Copying assets"
)

add_dependencies(csound-tuning-fork copy_assets)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/assets/ DESTINATION ${PROJECT_ASSETS_PATH})

# On Windows copy the DLL next to the EXE
option(BUNDLE_LIBRARIES "Bundle external libraries with the program (recommended e.g. on Windows)" OFF)
if(BUNDLE_LIBRARIES)
    zz_copy_runtime_libraries(csound-tuning-fork Csound::Csound6_CXX)
    zz_install_runtime_libraries(csound-tuning-fork Csound::Csound6_CXX)

    zz_copy_runtime_libraries(csound-tuning-fork SDL2::SDL2)
    zz_install_runtime_libraries(csound-tuning-fork SDL2::SDL2)
endif()
