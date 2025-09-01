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

#include "common.hpp"                   // my::common
#include "imgui_backend.hpp"            // my::imgui::backend
#include "ui.hpp"                       // my::ui

/* 1. Backend - Create Main Window
 * 2. ImGui - Setup context (style, io, fonts)
 * 3. Backend - Setup renderer
 * 4. UI - Setup (e.g. Csound)
 * 
 * 5. Run main loop
 *  a. Backend - Handle events and start new frame(io) (or signal end - enum return type)
 *  b. ImGui::NewFrame()
 *  c. UI - Run(io) (or signal end - same enum return type)
 *  d. ImGui::Render()
 *  e. Backend - Render(io, ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f))
 * 
 * 6. UI - Cleanup (e.g. Csound)
 * 7. Backend - Destroy Renderer
 * 8. ImGui::DestroyContext();
 * 9. Backend - Close Main Window
 */

/**
 * TODO: Explanation of the program flow above
 */
int main(int argc, char** argv) {
    try {
        // TODD
        
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "FATAL ERROR: " << e.what() << std::endl;
        return -1;
    }
}
