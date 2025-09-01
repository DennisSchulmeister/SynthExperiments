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

namespace my::ui {

/**
 * Set up ressources needed or controlled by the user interface, e.g.
 * the Csound audio backend. Called immediatelly before the main loop
 * after everything else has been set up.
 *
 * @param ctx - Shared user interface data
 * @throws Exception on fatal errors (e.g. my::common::fatal_error)
 */
void setup(my::common::ui_context ctx);

/**
 * Perform user interface logic during the main loop. Compose your
 * ImGui widgets here. Called in the main loop between `ImGui::NewFrame()`
 * and `ImGui::Render()`.
 *
 * @param ctx - Shared user interface data
 * @returns How to continue the main loop
 * @throws Exception on fatal errors (e.g. my::common::fatal_error)
 */
my::common::ui_result execute(my::common::ui_context ctx);

/**
 * Clean up ressources owned by the user interface. Called immediately
 * after the main loop before everything else is cleaned up.
 *
 * @throws Exception on fatal errors (e.g. my::common::fatal_error)
 */
void cleanup();

} // namespace my::ui
