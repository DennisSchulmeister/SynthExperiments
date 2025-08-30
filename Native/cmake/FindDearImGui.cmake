# - Static library to simplify adding Dear ImGui to a project -
#
# This will define:
#
#   DearImGui       - Static library target
#   DEAR_IMGUI_DIR  - Variable with the Dear ImGui source path
#
# The source will be searched by default in "../external/imgui" but you
# can overridde this by setting the (env) variable DEAR_IMGUI_DIR youself.
#
# Note that you must also add a Dear ImGui backend implementation by
# adding the corresponding "${DEAR_IMGUI_DIR}/backends/..." source
# files and dependencies like SDL2/OpenGL/...  to your build definition
#
# Better yet, don't use the `DearImGui` library directly. Instead define
# a wrapper library that adds your prefered backend and simply link
# against this. See `FindDearImGui_SDL2.cmake` for a working example.

# Allow hinting via DEAR_IMGUI_DIR
set(_DEAR_IMGUI_HINTS ${DEAR_IMGUI_DIR} $ENV{DEAR_IMGUI_DIR} "../external/imgui")
find_path(DEAR_IMGUI_DIR NAMES imgui.h HINTS ${_DEAR_IMGUI_HINTS})

if(NOT TARGET DearImGui)
    add_library(DearImGui STATIC
        ${DEAR_IMGUI_DIR}/imgui.cpp
        #${DEAR_IMGUI_DIR}/imgui_demo.cpp
        ${DEAR_IMGUI_DIR}/imgui_draw.cpp
        ${DEAR_IMGUI_DIR}/imgui_tables.cpp
        ${DEAR_IMGUI_DIR}/imgui_widgets.cpp
    )

    set_target_properties(DearImGui PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${DEAR_IMGUI_DIR};${DEAR_IMGUI_DIR}/backends"
    )
endif()
