# - Static library: Dear ImGui Toggle -
# Toggle widget for Dear ImGui. 
#
# Use it like any regular library dependency:
#
#   find_package(ImGuiToggle REQUIRED)
#   add_executable(myexe ...)
#   target_link_libraries(myexe PRIVATE ImGuiToggle)

find_package(ImGui REQUIRED)

# Allow hinting via IMGUI_TOGGLE_DIR
set(_IMGUI_TOGGLE_HINTS ${IMGUI_TOGGLE_DIR} $ENV{IMGUI_TOGGLE_DIR} "../external/imgui_toggle")
find_path(IMGUI_TOGGLE_DIR NAMES imgui_toggle.h HINTS ${_IMGUI_TOGGLE_HINTS})

if(NOT TARGET InGuiToggle)
    add_library(ImGuiToggle STATIC
        ${IMGUI_TOGGLE_DIR}/imgui_toggle.cpp
        ${IMGUI_TOGGLE_DIR}/imgui_toggle_palette.cpp
        ${IMGUI_TOGGLE_DIR}/imgui_toggle_presets.cpp
        ${IMGUI_TOGGLE_DIR}/imgui_toggle_renderer.cpp
    )

    target_link_libraries(ImGuiToggle PRIVATE ImGui)
    set_target_properties(ImGuiToggle PROPERTIES INTERFACE_INCLUDE_DIRECTORIES "${IMGUI_TOGGLE_DIR}")
endif()
