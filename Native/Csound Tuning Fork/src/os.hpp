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

namespace my::os {

/**
 * Get the directory of the process executable, mainly to locate static
 * assets when they are not installed system-wide. This might fall back
 * to the current workdir on some systems. Returns an empty string on
 * failure.
 *
 * @returns Base path to locate static assets
 */
std::filesystem::path get_executable_dir();

} // namespace my::os
