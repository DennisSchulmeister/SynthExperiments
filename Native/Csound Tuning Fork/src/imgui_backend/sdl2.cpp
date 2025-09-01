/* Csound native app - Tuning Fork
 * (C) 2025 Dennis Schulmeister-Zimolong <dennis@windows3.de>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 */
#include "../imgui_backend.hpp"

#include <imgui_impl_sdl2.h>
#include <imgui_impl_sdlrenderer2.h>
#include <SDL.h>

namespace my::imgui::backend {

/**
 * Create the main window and initialize the ImGui backend.
 */
my::common::ui_error create_main_window() {
    /*
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER) != 0) {
        std::cerr << "SDL Error: " << SDL_GetError() << std::endl;
        return -1;
    }
    */

    // TODO
    return {};
}

/**
 * Set up the graphics renderer.
 */
my::common::ui_error setup_renderer(my::common::ui_context ctx) {
    // TODO
    return {};
}

/**
 * Handle events and start a new frame.
 */
my::common::ui_result start_frame(my::common::ui_context ctx) {
    // TODO
    return {};
}

/**
 * Draw current frame on the screen.
 */
my::common::ui_result end_frame(my::common::ui_context ctx) {
    // TODO
    return {};
}

/**
 * Destroy graphics renderer.
 */
my::common::ui_error destroy_renderer() {
    // TODO
    return {};
}

/**
 * Destroying the main window and all related ressources.
 */
my::common::ui_error destroy_main_window() {
    // TODO
    return {};
}

} // namespace my::imgui::backend
