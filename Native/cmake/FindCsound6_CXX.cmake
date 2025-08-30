# - Try to find Csound 6 (C++ API) -
#
# Once done, this will define
# 
#   Csound6_CXX_FOUND           - System has libcsound
#   Csound6_CXX_INCLUDE_DIRS    - Where to find csound.hpp
#   Csound6_CXX_LIBRARIES       - Libraries to link
#   Csound::Csound6_CXX         - Imported target

# Allow hinting via CSOUND6_CXX_DIR
set(_CSOUND6_CXX_HINTS
    ${CSOUND6_CXX_DIR}
    $ENV{CSOUND6_CXX_DIR}
    "C:/Program Files/Csound6_x64"
    "/usr"
    "/usr/local"
    "/opt/csound"
)

find_path(Csound6_CXX_INCLUDE_DIR
    NAMES csound.hpp
    HINTS ${_CSOUND6_CXX_HINTS}
    PATH_SUFFIXES include include/csound
)

find_library(Csound6_CXX_LIBRARY
    NAMES csound64 csound
    HINTS ${_CSOUND6_CXX_HINTS}
    PATH_SUFFIXES lib build/lib
)

find_library(Csnd6_CXX_LIBRARY
    NAMES csnd6
    HINTS ${_CSOUND6_CXX_HINTS}
    PATH_SUFFIXES lib build/lib
)
 
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Csound6_CXX
    REQUIRED_VARS Csound6_CXX_LIBRARY Csnd6_CXX_LIBRARY Csound6_CXX_INCLUDE_DIR
)

if(Csound6_CXX_FOUND)
    set(Csound6_CXX_INCLUDE_DIRS ${Csound6_CXX_INCLUDE_DIR})
    set(Csound6_CXX_LIBRARIES ${Csound6_CXX_LIBRARY} ${Csnd6_CXX_LIBRARY})
    
    if(NOT TARGET Csound::Csound6_CXX)
        add_library(Csound::Csound6_CXX UNKNOWN IMPORTED)
        set_target_properties(Csound::Csound6_CXX PROPERTIES
            IMPORTED_LOCATION "${Csound6_CXX_LIBRARY}"
            INTERFACE_LINK_LIBRARIES "${Csnd6_CXX_LIBRARY}"
            INTERFACE_INCLUDE_DIRECTORIES "${Csound6_CXX_INCLUDE_DIR}"
        )
    endif()
endif()
