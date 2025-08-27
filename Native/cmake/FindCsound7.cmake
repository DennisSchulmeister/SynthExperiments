# - Try to find Csound 7 (C API) [UNTESTED!!] -
# [There seems to no difference to Csound6 for the C version except for the Windows install path]
# Once done, this will define
# 
#   Csound7_FOUND          - System has libcsound
#   Csound7_INCLUDE_DIRS   - Where to find csound.h
#   Csound7_LIBRARIES      - Libraries to link
#   Csound::Csound7        - Imported target

# Allow hinting via CSOUND7_DIR
set(_CSOUND7_HINTS
    ${CSOUND7_DIR}
    ENV CSOUND7_DIR
    "C:/Program Files/Csound7_x64"
    "/usr"
    "/usr/local"
    "/opt/csound"
)

find_path(Csound7_INCLUDE_DIR
    NAMES csound.h
    HINTS ${_CSOUND7_HINTS}
    PATH_SUFFIXES include include/csound
)

find_library(Csound7_LIBRARY
    NAMES csound64 csound
    HINTS ${_CSOUND7_HINTS}
    PATH_SUFFIXES lib build/lib
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Csound7
    REQUIRED_VARS Csound7_LIBRARY Csound7_INCLUDE_DIR
)

if(Csound7_FOUND)
    set(Csound7_INCLUDE_DIRS ${Csound7_INCLUDE_DIR})
    set(Csound7_LIBRARIES ${Csound7_LIBRARY})
    
    if(NOT TARGET Csound::Csound7)
        add_library(Csound::Csound7 UNKNOWN IMPORTED)
        set_target_properties(Csound::Csound7 PROPERTIES
            IMPORTED_LOCATION "${Csound7_LIBRARIES}"
            INTERFACE_INCLUDE_DIRECTORIES "${Csound7_INCLUDE_DIRS}"
        )
    endif()
endif()
