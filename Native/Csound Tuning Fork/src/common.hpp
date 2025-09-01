/* Csound native app - Tuning Fork
 * (C) 2025 Dennis Schulmeister-Zimolong <dennis@windows3.de>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 */
#pragma once

#include <stdexcept>    // std::runtime_error
#include <imgui.h>      // ImGuiIO, ImVec4
#include <string>       // std::string

namespace my::common {

/**
 * Shared data between main module (owner), imgui backend and UI.
 */
struct ui_context {
    ImGuiIO& io;
    ImVec4 clear_color;
};

/**
 * Possible ways to continue the main loop.
 */
enum class ui_result {
    /**
     * Keep On Running - The Spencer Davis Group (1965)
     */
    goon,

    /**
     * Exit program.
     */
    exit,
};

/**
 * Fatal error that will abort the program.
 */
class fatal_error : public std::runtime_error {
public:
    explicit fatal_error(const std::string& message)
        : std::runtime_error(message) {}
};

} // namespace my::common
