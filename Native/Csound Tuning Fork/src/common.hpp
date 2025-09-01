/* Csound native app - Tuning Fork
 * (C) 2025 Dennis Schulmeister-Zimolong <dennis@windows3.de>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 */
#pragma once

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
enum class ui_result_value {
    /**
     * Keep On Running - The Spencer Davis Group (1965)
     */
    goon,

    /**
     * Exit normally.
     */
    exit,

    /**
     * Abort due to a fatal error.
     */
    abort
};

/**
 * Return type for UI functions to communicate back to the main loop
 * if the program shall continue to run, exit or abort.
 */
struct ui_result {
    /**
     * Result value to signal the main loop how to continue.
     */
    ui_result_value value = ui_result_value::goon;

    /**
     * Optional (error) message to be printed on the console.
     */
    std::string message = "";
};

/**
 * Simplified return type for functions which can only succeed or fail.
 */
struct ui_error {
    /**
     * A fatal error occured, abort program.
     */
    bool error = false;
    
    /**
     * Error message to be printed on the console.
     */
    std::string message = "";
};

} // namespace my::common
