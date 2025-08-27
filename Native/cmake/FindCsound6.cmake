# - Try to find Csound 6 (C API) -
#
# Once done, this will define
# 
#   Csound6_FOUND          - System has libcsound
#   Csound6_INCLUDE_DIRS   - Where to find csound.h
#   Csound6_LIBRARIES      - Libraries to link
#   Csound::Csound6        - Imported target

# Allow hinting via CSOUND6_DIR
set(_CSOUND6_HINTS
    ${CSOUND6_DIR}
    ENV CSOUND6_DIR
    "C:/Program Files/Csound6_x64"
    "/usr"
    "/usr/local"
    "/opt/csound"
)

find_path(Csound6_INCLUDE_DIR
    NAMES csound.h
    HINTS ${_CSOUND6_HINTS}
    PATH_SUFFIXES include include/csound
)

find_library(Csound6_LIBRARY
    NAMES csound64 csound
    HINTS ${_CSOUND6_HINTS}
    PATH_SUFFIXES lib build/lib
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Csound6
    REQUIRED_VARS Csound6_LIBRARY Csound6_INCLUDE_DIR
)

if(Csound6_FOUND)
    set(Csound6_INCLUDE_DIRS ${Csound6_INCLUDE_DIR})
    set(Csound6_LIBRARIES ${Csound6_LIBRARY})
    
    if(NOT TARGET Csound::Csound6)
        add_library(Csound::Csound6 UNKNOWN IMPORTED)
        set_target_properties(Csound::Csound6 PROPERTIES
            IMPORTED_LOCATION "${Csound6_LIBRARIES}"
            INTERFACE_INCLUDE_DIRECTORIES "${Csound6_INCLUDE_DIRS}"
        )
    endif()
endif()
