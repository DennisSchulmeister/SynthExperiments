# - Static library: Dear ImGui Knobs -
# Rotary knob widget for Dear ImGui. 
#
# Use it like any regular library dependency:
#
#   find_package(ImGuiKnobs REQUIRED)
#   add_executable(myexe ...)
#   target_link_libraries(myexe PRIVATE ImGuiKnobs)

find_package(ImGui REQUIRED)

# Allow hinting via IMGUI_KNOBS_DIR
set(_IMGUI_KNOBS_HINTS ${IMGUI_KNOBS_DIR} $ENV{IMGUI_KNOBS_DIR} "../external/imgui-knobs")
find_path(IMGUI_KNOBS_DIR NAMES imgui-knobs.h HINTS ${_IMGUI_KNOBS_HINTS})

if(NOT TARGET InGuiKnobs)
    add_library(ImGuiKnobs STATIC
        ${IMGUI_KNOBS_DIR}/imgui-knobs.cpp
    )

    target_link_libraries(ImGuiKnobs PRIVATE ImGui)
    set_target_properties(ImGuiKnobs PROPERTIES INTERFACE_INCLUDE_DIRECTORIES "${IMGUI_KNOBS_DIR}")
endif()
