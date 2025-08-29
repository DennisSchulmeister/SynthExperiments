/* Csound native app - Minimal skeleton
 * (C) 2025 Dennis Schulmeister-Zimolong <dennis@windows3.de>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 */
#include "assets.hpp"

#include "config.hpp"   // ASSET_PATH
#include "os.hpp"       // my::os

namespace my::assets {

/**
 * Get path of an asset file or nothing, if not found.
 */
std::optional<std::filesystem::path> get_path(std::filesystem::path filename) {
    static auto executable_dir = my::os::get_executable_dir();
    
    auto path = executable_dir / filename;
    if (std::filesystem::exists(path)) return path;

    path = std::filesystem::path{ASSET_PATH} / filename;
    if (std::filesystem::exists(path)) return path;

    return std::nullopt;
}

} // namespace my::assets
