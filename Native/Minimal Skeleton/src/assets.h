/* Csound native app - Minimal skeleton
 * (C) 2025 Dennis Schulmeister-Zimolong <dennis@windows3.de>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 */
#pragma once

#include <stdbool.h>    // bool, true, false (before C23)
#include <stddef.h>     // size_t

/**
 * To be called soon after program start-up to initialize the internal
 * variables. This tries to fo find the executable path to allow finding
 * asset files relative to the executable file during local testing or
 * on platforms like Windows.
 */
void assets_init();

/**
 * Get full path of an asset file. Returns a string with the first match
 * where the file is found:
 *
 * 1. Relative to the executable.
 * 2. Relative to the ASSET_PATH set via Cmake.
 *
 * @param out - Output buffer
 * @param len - Output buffer size
 * @param count - Number of path segments to join
 * @param ... - Path segments (will be joined)
 * @returns true on success, false if the path cannot be found
 */
bool assets_get_path(char* out, size_t len, size_t count, ...);
