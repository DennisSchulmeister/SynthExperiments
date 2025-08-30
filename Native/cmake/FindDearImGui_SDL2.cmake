# - Static library: Dear ImGui + SDL2 + SDL Renderer -
# Wrapper around the core DearImGui library. 
#
# Use it like any regular library dependency:
#
#   find_package(DearImGui_SDL2 REQUIRED)
#   add_executable(myexe ...)
#   target_link_libraries(myexe PRIVATE DearImGui_SDL2)
#
# That's all, folks! You need to have SDL2 development headers intalled.

# Find SDL2 - see: https://wiki.libsdl.org/SDL2/README-cmake
find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)
find_package(SDL2 REQUIRED CONFIG COMPONENTS SDL2main)

# Wrap DearImGui from same directory
find_package(DearImGui REQUIRED)

add_library(DearImGui_SDL2 STATIC
    ${DEAR_IMGUI_DIR}/backends/imgui_impl_sdl2.cpp
    ${DEAR_IMGUI_DIR}/backends/imgui_impl_sdlrenderer2.cpp
)

if(TARGET SDL2::SDL2main)
    # Only available/required for Windows GUI applications
    # MUST be added before SDL2::SDL2 (or SDL2::SDL2-static)
    target_link_libraries(DearImGui_SDL2 PUBLIC SDL2::SDL2main)
endif()

target_link_libraries(DearImGui_SDL2 PUBLIC DearImGui)
target_link_libraries(DearImGui_SDL2 PUBLIC SDL2::SDL2)
