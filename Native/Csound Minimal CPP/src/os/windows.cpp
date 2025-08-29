/* Csound native app - Minimal skeleton
 * (C) 2025 Dennis Schulmeister-Zimolong <dennis@windows3.de>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 */
#include "../os.hpp"

#include <array>        // std::array
#include <filesystem>   // std::filesystem
#include <windows.h>    // GetModuleFileNameA

namespace my::os {

/**
 * Get the directory of the process executable or fall back to the current workdir.
 */
std::filesystem::path get_executable_dir() {
    std::array<char, MAX_PATH> path{};
    DWORD length = GetModuleFileNameA(nullptr, path.data(), static_cast<DWORD>(path.size()));

    if (length == 0 || length == path.size()) {
        return std::filesystem::current_path();
    }

    return std::filesystem::path exe_path(path.data()).parent_path();
}

} // namespace my::os
