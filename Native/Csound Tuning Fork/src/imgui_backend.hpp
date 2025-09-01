/* Csound native app - Tuning Fork
 * (C) 2025 Dennis Schulmeister-Zimolong <dennis@windows3.de>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 */
#pragma once

#include <imgui.h>      // ImGui::
#include "common.hpp"   // my::common

namespace my::imgui::backend {

/**
 * Create the main window, set up required libraries (e.g. SDL) and
 * initialize the ImGui backend. Called at the very start of the program.
 * 
 * @throws Exception on fatal errors (e.g. my::common::fatal_error)
 */
void create_main_window();

/**
 * Finish initialization by setting up the graphics renderer. Called
 * after the main window and the ImGui context have been fully initialized.
 * 
 * @param ctx - Shared user interface data
 * @throws Exception on fatal errors (e.g. my::common::fatal_error)
 */
void setup_renderer(my::common::ui_context ctx);

/**
 * Handle window and I/O events, pass the events to ImGui and prepare
 * the backend to start a new frame. Called at the beginning of the
 * ian loop before `ImGui::NewFrame()`.
 *
 * @param ctx - Shared user interface data
 * @returns How to continue the main loop
 * @throws Exception on fatal errors (e.g. my::common::fatal_error)
 */
my::common::ui_result start_frame(my::common::ui_context ctx);

/**
 * Finish current frame and draw it on the screen. Called at the end of
 * the main loop after `ImGui::Render()`.
 *
 * @param ctx - Shared user interface data
 * @throws Exception on fatal errors (e.g. my::common::fatal_error)
 */
void end_frame(my::common::ui_context ctx);

/**
 * Destroy graphics renderer during normal program shutdown. Called
 * after the main loop befor `ImGui::DestroyContext()`.
 *
 * @throws Exception on fatal errors (e.g. my::common::fatal_error)
 */
void destroy_renderer();

/**
 * Finish normal program shutdown by destroying the main window and all
 * related ressources. Called right after `ImGui::DestroyContext()`.
 *
 * @throws Exception on fatal errors (e.g. my::common::fatal_error)
 */
void destroy_main_window();

} // namespace my::imgui::backend
