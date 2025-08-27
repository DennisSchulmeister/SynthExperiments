# - Try to find Csound 7 (C++ API) [UNTESTED!!] -
# [It seems that libcsnd6 is not needed anymore]
#
# Once done, this will define
# 
#   Csound7_CXX_FOUND           - System has libcsound
#   Csound7_CXX_INCLUDE_DIRS    - Where to find csound.hpp
#   Csound7_CXX_LIBRARIES       - Libraries to link
#   Csound::Csound7_CXX         - Imported target

# Allow hinting via CSOUND7_CXX_DIR
set(_CSOUND7_CXX_HINTS
    ${CSOUND7_CXX_DIR}
    ENV CSOUND7_CXX_DIR
    "C:/Program Files/Csound7_x64"
    "/usr"
    "/usr/local"
    "/opt/csound"
)

find_path(Csound7_CXX_INCLUDE_DIR
    NAMES csound.hpp
    HINTS ${_CSOUND7_CXX_HINTS}
    PATH_SUFFIXES include include/csound
)

find_library(Csound7_CXX_LIBRARY
    NAMES csound64 csound
    HINTS ${_CSOUND7_CXX_HINTS}
    PATH_SUFFIXES lib build/lib
)
 
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Csound7_CXX
    REQUIRED_VARS Csound7_CXX_LIBRARY Csound7_CXX_INCLUDE_DIR
)

if(Csound7_CXX_FOUND)
    set(Csound7_CXX_INCLUDE_DIRS ${Csound7_CXX_INCLUDE_DIR})
    set(Csound7_CXX_LIBRARIES ${Csound7_CXX_LIBRARY})
    
    if(NOT TARGET Csound::Csound7_CXX)
        add_library(Csound::Csound7_CXX UNKNOWN IMPORTED)
        set_target_properties(Csound::Csound7_CXX PROPERTIES
            IMPORTED_LOCATION "${Csound7_CXX_LIBRARY}"
            INTERFACE_INCLUDE_DIRECTORIES "${Csound7_CXX_INCLUDE_DIR}"
        )
    endif()
endif()
