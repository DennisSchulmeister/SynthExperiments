/* Csound native app - Minimal skeleton
 * (C) 2025 Dennis Schulmeister-Zimolong <dennis@windows3.de>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 */
#include "../os.hpp"

#include <array>            // std::array
#include <climits>          // PATH_MAX
#include <cstdlib>          // realpath
#include <filesystem>       // std::filesystem
#include <string>           // std::string

namespace my::os {

/**
 * Get the directory of the process executable or fall back to the current workdir.
 */
std::filesystem::path get_executable_dir() {
    // On Linux we can simply resolve /proc/self/exe. On systems where
    // this is not available (typically BSD) we fallback to the workdir.
    std::array<char, PATH_MAX> resolved{};
    
    if (realpath("/proc/self/exe", resolved.data()) == nullptr) {
        return std::filesystem::current_path();
    }

    return std::filesystem::path(resolved.data()).parent_path();
}

} // namespace my::os
