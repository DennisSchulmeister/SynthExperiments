cmake_minimum_required(VERSION 3.10)
project(csound-minimal-c C)      # C++ = CXX

# Include custom functions
include("${CMAKE_CURRENT_SOURCE_DIR}/../cmake/CmakeFunctions.cmake")

# Look for custom find modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../cmake")
find_package(Csound6 REQUIRED)   # C++ = Csound6_CXX

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

if(UNIX)
    include(GNUInstallDirs)
else()
    set(${CMAKE_INSTALL_LIBDIR} "lib")
    set(${CMAKE_INSTALL_DATADIR} "share")
    set(${CMAKE_INSTALL_INCLUDEDIR} "include")
    set(${CMAKE_INSTALL_BINDIR} "bin")
endif()

add_executable(csound-minimal-c ${SOURCES})
target_link_libraries(csound-minimal-c PRIVATE Csound::Csound6)
install(TARGETS csound-minimal-c DESTINATION ${CMAKE_INSTALL_BINDIR})

# Copy static assets next to the EXE
add_custom_target(copy_assets ALL
    COMMAND ${CMAKE_COMMAND} -E make_directory assets
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/assets assets
    COMMENT "Copying assets"
)

add_dependencies(csound-minimal-c copy_assets)

set(CMAKE_INSTALL_DATADIR "share/${PROJECT_NAME}")
set(PROJECT_ASSETS_PATH "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_DATADIR}")
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/assets/ DESTINATION ${PROJECT_ASSETS_PATH})

# Generate config.h file
configure_file(config.h.in ${CMAKE_BINARY_DIR}/config.h)
include_directories(${CMAKE_BINARY_DIR})

# On Windows copy the DLL next to the EXE
option(BUNDLE_LIBRARIES "Bundle external libraries with the program (recommended e.g. on Windows)" OFF)
if(BUNDLE_LIBRARIES)
    zz_copy_runtime_libraries(csound-minimal-c Csound::Csound6)
    zz_install_runtime_libraries(csound-minimal-c Csound::Csound6)
endif()
