# - Static library to simplify adding Dear ImGui to a project -
#
# This will define:
#
#   ImGui       - Static library target
#   IMGUI_DIR   - Variable with the Dear ImGui source path
#
# The source will be searched by default in "../external/imgui" but you
# can overridde this by setting the (env) variable IMGUI_DIR youself.
#
# Note that you must also add a Dear ImGui backend implementation by
# adding the corresponding "${IMGUI_DIR}/backends/..." source files and
# dependencies like SDL2/OpenGL/...  to your build definition
#
# Better yet, don't use the `ImGui` library directly. Instead define
# a wrapper library that adds your prefered backend and simply link
# against this. See `FindImGui_SDL2.cmake` for a working example.

# Allow hinting via IMGUI_DIR
set(_IMGUI_HINTS ${IMGUI_DIR} $ENV{IMGUI_DIR} "../external/imgui")
find_path(IMGUI_DIR NAMES imgui.h HINTS ${_IMGUI_HINTS})

if(NOT TARGET ImGui)
    add_library(ImGui STATIC
        ${IMGUI_DIR}/imgui.cpp
        #${IMGUI_DIR}/imgui_demo.cpp
        ${IMGUI_DIR}/imgui_draw.cpp
        ${IMGUI_DIR}/imgui_tables.cpp
        ${IMGUI_DIR}/imgui_widgets.cpp
    )

    set_target_properties(ImGui PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${IMGUI_DIR};${IMGUI_DIR}/backends"
    )
endif()
