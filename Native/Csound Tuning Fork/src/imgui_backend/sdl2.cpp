/* Csound native app - Tuning Fork
 * (C) 2025 Dennis Schulmeister-Zimolong <dennis@windows3.de>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 */
#include "../imgui_backend.hpp"

// The following code is based on imgui/examples/example_sdl2_sdlrenderer2/main.cpp
// in the ImGui source tree. It has been cleaned up a little bit and split into the
// functions below to separate "platform" from "application" logic.

#include <imgui_impl_sdl2.h>
#include <imgui_impl_sdlrenderer2.h>
#include <SDL.h>

#ifdef _WIN32
    #include <windows.h>    // SetProcessDPIAware()
#endif

namespace my::imgui::backend {
SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;

/**
 * Throw exception with the last error from SDL.
 */
void throw_sdl_error() {
    throw my::common::fatal_error(std::string("SDL Error: ") + SDL_GetError());
}

/**
 * Create the main window and initialize the ImGui backend.
 */
void create_main_window(const std::string& title, int width, int height) {
    #ifdef _WIN32
        ::SetProcessDPIAware();
    #endif

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0) {
        throw_sdl_error();
    }

    #ifdef SDL_HINT_IME_SHOW_UI
        SDL_SetHint(SDL_HINT_IME_SHOW_UI, "1");
    #endif

    float main_scale = ImGui_ImplSDL2_GetContentScaleForDisplay(0);

    window = SDL_CreateWindow(
        /* title */ title.c_str(),
        /* x     */ SDL_WINDOWPOS_CENTERED,
        /* y     */ SDL_WINDOWPOS_CENTERED,
        /* w     */ (int)(main_scale * width),
        /* h     */ (int)(main_scale * height),
        /* flags */ SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI
    );

    if (window == nullptr) throw_sdl_error();

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) throw_sdl_error();

    SDL_RendererInfo info;
    SDL_GetRendererInfo(renderer, &info);
    SDL_Log("Current SDL_Renderer: %s", info.name);
}

/**
 * Set up the graphics renderer.
 */
void setup_renderer(my::common::ui_context ctx) {
    ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
    ImGui_ImplSDLRenderer2_Init(renderer);
}

/**
 * Handle events and start a new frame.
 *
 * Not strictly necessary in our case, as we don't render a game or other
 * kind of appication behind the UI. But for the sake of completeness:
 *
 * - ctx.io.WantCaptureMouse: Send mouse events to ImGui
 * - ctx.io.WantCaptureKeyboard: Send keyboard events to ImGui
 *
 * ImGui uses these flags to inform  the application that the corresponding
 * events should not be handled by the background application. Nevertheless
 * we can always send all events to ImGui, since ImGui will silently ignore
 * the ones it doesn't need.
 */
my::common::main_loop_action start_frame(my::common::ui_context ctx) {
    my::common::main_loop_action result = my::common::main_loop_action::keep_running;
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        ImGui_ImplSDL2_ProcessEvent(&event);

        if ((event.type == SDL_QUIT) ||
            (event.type == SDL_WINDOWEVENT &&
             event.window.event == SDL_WINDOWEVENT_CLOSE &&
             event.window.windowID == SDL_GetWindowID(window))
        ) {
            result = my::common::main_loop_action::exit_program;
        }
    }

    if (SDL_GetWindowFlags(window) & SDL_WINDOW_MINIMIZED) {
        SDL_Delay(10);
        return my::common::main_loop_action::remain_inactive;
    }

    ImGui_ImplSDLRenderer2_NewFrame();
    ImGui_ImplSDL2_NewFrame();

    return result;
}

/**
 * Draw current frame on the screen.
 */
void end_frame(my::common::ui_context ctx) {
    SDL_RenderSetScale(renderer, ctx.io.DisplayFramebufferScale.x, ctx.io.DisplayFramebufferScale.y);

    SDL_SetRenderDrawColor(
        /*renderer */ renderer,
        /* r */       (Uint8) ctx.clear_color.x * 255,
        /* g */       (Uint8) ctx.clear_color.y * 255,
        /* b */       (Uint8) ctx.clear_color.z * 255,
        /* a */       (Uint8) ctx.clear_color.w * 255
    );

    SDL_RenderClear(renderer);

    ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), renderer);
    SDL_RenderPresent(renderer);
}

/**
 * Destroy graphics renderer.
 */
void destroy_renderer() {
    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
}

/**
 * Destroy the main window and all related ressources.
 */
void destroy_main_window() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

} // namespace my::imgui::backend
