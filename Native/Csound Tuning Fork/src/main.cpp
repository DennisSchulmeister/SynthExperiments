/* Csound native app - Tuning Fork
 * (C) 2025 Dennis Schulmeister-Zimolong <dennis@windows3.de>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 */
#include <exception>                    // std::exception
#include <imgui.h>                      // ImGui::, ImGuiIO, ImGuiStyle, ImVec4
#include <iostream>                     // std::cout, std::cerr, std::endl

#include "assets.hpp"                   // my::assets
#include "common.hpp"                   // my::common
#include "imgui_backend.hpp"            // my::imgui::backend
#include "ui.hpp"                       // my::ui

/**
 * Set up ImGui context with styling and fonts etc.
 */
my::common::ui_context imgui_setup_context(float dpi_scale) {
    // Create ImGui context
    ImGui::CreateContext();

    my::common::ui_context ctx = {
        .io = ImGui::GetIO(),
        .clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f),
        .dpi_scale = dpi_scale
    };

    ctx.io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    ctx.io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    // Setup style and scaling
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsLight();

    ImGuiStyle& style = ImGui::GetStyle();
    style.ScaleAllSizes(dpi_scale);

    ctx.io.ConfigDpiScaleFonts = true;          // [Experimental] Automatically scale fonts (but no sizes/padding, yet) when Monitor DPI changes.
    ctx.io.ConfigDpiScaleViewports = true;      // [Experimental] Scale ImGui and Platform Windows when Monitor DPI changes.

    // Load Fonts
    style.FontSizeBase = 14.0f;

    ImFont* font = nullptr;
    auto font_file = my::assets::get_path("assets/OpenSans/OpenSans-VariableFont_wdth,wght.ttf");
    if (font_file) font = ctx.io.Fonts->AddFontFromFileTTF(font_file->c_str());

    if (font == nullptr) {
        std::cerr << "WARNING - Unable to load font OpenSans. Falling back to default font." << std::endl;
        ctx.io.Fonts->AddFontDefault();
    }

    return ctx;
}

/**
 * The following code is based on the examples in the ImGui source tree.
 * But to increase the separation of concerns and make it easy to replace
 * the ImGui backend when porting to another operating system, the algorithm
 * has been split into multiple functions in different compilation units:
 *
 * 1. main.cpp: General ImGui setup and main loop
 * 2. imgui_backend/*.cpp: Backend-specific code
 * 3. ui.cpp: Application UI logic
 *
 * The program flow is still almost identical to the ImGui examples,
 * especially the SDL2 + SDLRenderer2 example. But the others are very
 * similar. The sequence of actions is:
 *
 *   1. Create Main Window
 *   2. Setup ImGui (style, io, fonts)
 *   3. Create renderer
 *   4. Initialize UI logic
 *
 *   5. Run main loop
 *      a. Handle events
 *      b. Start new frame
 *      c. Run UI logic
 *      d. Render UI
 *
 *   6. Destroy UI ressources
 *   7. Destroy Renderer
 *   8. Destroy ImGui Context
 *   9. Destroy Main Window
 */
int main(int argc, char** argv) {
    try {
        float dpi_scale = my::imgui::backend::create_main_window("Tuning Fork", 320, 240);

        auto ctx = imgui_setup_context(dpi_scale);
        my::imgui::backend::setup_renderer(ctx);
        my::ui::setup(ctx);

        bool running = true;

        while (running) {
            auto action = my::imgui::backend::start_frame(ctx);
            if (action == my::common::main_loop_action::exit_program) running = false;

            if (action != my::common::main_loop_action::remain_inactive) {
                ImGui::NewFrame();

                action = my::ui::execute(ctx);
                if (action == my::common::main_loop_action::exit_program) running = false;

                ImGui::Render();
                my::imgui::backend::end_frame(ctx);
            }
        }

        my::ui::cleanup();
        my::imgui::backend::destroy_renderer();
        ImGui::DestroyContext();

        my::imgui::backend::destroy_main_window();
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "ERROR - " << e.what() << std::endl;
        return -1;
    }
}
