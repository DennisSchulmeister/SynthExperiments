/* Csound native app - Tuning Fork
 * (C) 2025 Dennis Schulmeister-Zimolong <dennis@windows3.de>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 */
#include "../os.hpp"

#include <array>            // std::array
#include <filesystem>       // std::filesystem
#include <string>           // std::string
#include <climits>          // PATH_MAX
#include <mach-o/dyld.h>    // _NSGetExecutablePath
#include <cstdlib>          // realpath

namespace my::os {

/**
 * Get the directory of the process executable or fall back to the current workdir.
 */
std::filesystem::path get_executable_dir() {
    // Try to get the executable path
    std::array<char, PATH_MAX> raw_path{};
    uint32_t size = raw_path.size();

    if (_NSGetExecutablePath(raw_path.data(), &size) != 0) {
        // Buffer too small or another error
        return std::filesystem::current_path();
    }

    // Resolve any symlinks and canonicalize the path
    std::array<char, PATH_MAX> resolved{};

    if (realpath(raw_path.data(), resolved.data()) == nullptr) {
        return std::filesystem::current_path();
    }

    return std::filesystem::path(resolved.data()).parent_path();
}

} // namespace my::os
