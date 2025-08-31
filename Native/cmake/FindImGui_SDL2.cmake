# - Static library: Dear ImGui + SDL2 + SDL Renderer -
# Wrapper around the core Dear ImGui library. 
#
# Use it like any regular library dependency:
#
#   find_package(ImGui_SDL2 REQUIRED)
#   add_executable(myexe ...)
#   target_link_libraries(myexe PRIVATE ImGui_SDL2)
#
# That's all, folks! You need to have SDL2 development headers intalled.
# This also adds ImGui propper and SDL2 to your project.

# Find SDL2 - see: https://wiki.libsdl.org/SDL2/README-cmake
find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)
find_package(SDL2 REQUIRED CONFIG COMPONENTS SDL2main)

# Wrap ImGui from same directory
find_package(ImGui REQUIRED)

if(NOT TARGET ImGui_SDL2)
    add_library(ImGui_SDL2 STATIC
        ${IMGUI_DIR}/backends/imgui_impl_sdl2.cpp
        ${IMGUI_DIR}/backends/imgui_impl_sdlrenderer2.cpp
    )

    if(TARGET SDL2::SDL2main)
        # Only available/required for Windows GUI applications
        # MUST be added before SDL2::SDL2 (or SDL2::SDL2-static)
        target_link_libraries(ImGui_SDL2 PUBLIC SDL2::SDL2main)
    endif()

    target_link_libraries(ImGui_SDL2 PUBLIC ImGui)
    target_link_libraries(ImGui_SDL2 PUBLIC SDL2::SDL2)
endif()
