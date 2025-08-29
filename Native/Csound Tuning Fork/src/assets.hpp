/* Csound native app - Tuning Fork
 * (C) 2025 Dennis Schulmeister-Zimolong <dennis@windows3.de>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 */
#pragma once

#include <filesystem>   // std::filesystem
#include <optional>     // std::optional, std::nullopt

namespace my::assets {

/**
 * Get full path of an asset file. Returns the first match where the
 * file is found:
 *
 * 1. Relative to the executable.
 * 2. Relative to the ASSET_PATH set via Cmake.
 *
 * @param filename - Relative path of the searched asset
 * @returns Full path or nothing if the file cannot be found
 */
std::optional<std::filesystem::path> get_path(std::filesystem::path filename);

} // namespace my::assets
