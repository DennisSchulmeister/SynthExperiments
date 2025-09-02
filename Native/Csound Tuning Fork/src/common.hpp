/* Csound native app - Tuning Fork
 * (C) 2025 Dennis Schulmeister-Zimolong <dennis@windows3.de>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 */
#pragma once

#include <stdexcept>            // std::runtime_error
#include <imgui.h>              // ImGuiIO, ImVec4
#include <string>               // std::string
#include <source_location>      // std::source_location

namespace my::common {

/**
 * Shared data between main module (owner), imgui backend and UI.
 */
struct ui_context {
    ImGuiIO& io;
    ImVec4 clear_color;
    float dpi_scale;
};

/**
 * Possible ways to continue the main loop.
 */
enum class main_loop_action {
    /**
     * Keep On Running - The Spencer Davis Group (1965)
     */
    keep_running,

    /**
     * Keep running in background but don't process UI logic or render
     * any graphics, because the main window is currently invisible.
     */
    remain_inactive,

    /**
     * Exit program.
     */
    exit_program,
};

/**
 * Fatal error that will abort the program. Also captures the source
 * location, where the error occured and includes it in the error
 * message (C++20).
 *
 * Note that since C++23 we could also include a stack trace, but this
 * requires debug symbols to work and linking to platform-dependend
 * libraries for runtime support. Since we are not expecting too deep
 * call stacks, let's keep it simple for now and omit the stack trace.
 */
class fatal_error : public std::runtime_error {
public:
    /**
     * Constructor to create a new exception to be thrown.
     *
     * @param msg - Error message
     * @param loc - Caller source position (automatically captured through the default value)
     */
    explicit fatal_error(
        const std::string& msg,
        const std::source_location loc = std::source_location::current()
    )
        : std::runtime_error(formatMessage(msg, loc)) {}

private:
    /**
     * Format the exception message to include the source location.
     *
     * @param msg - Error message
     * @param loc - Source position
     * @returns Formatted exception message
     */
    static std::string formatMessage(const std::string& msg, const std::source_location& loc) {
        return msg +
               "\n  at " + loc.file_name() +
               ":" + std::to_string(loc.line()) +
               " in function " + loc.function_name();
    }
};

} // namespace my::common
