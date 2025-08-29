/* Csound native app - Minimal skeleton
 * (C) 2025 Dennis Schulmeister-Zimolong <dennis@windows3.de>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 */
#pragma once

#include <stdarg.h>     // va_list, va_start, va_arg, va_end
#include <stddef.h>     // size_t
#include <stdbool.h>    // bool, true, false (before C23)

/**
 * Get the current work directory of the process. Returns an empty string
 * on failure.
 *
 * @param cwd - Output buffer
 * @param len - Output buffer size
 */
void os_get_current_workdir(char* cwd, size_t len);

/**
 * Get the directory of the process executable, mainly to locate static
 * assets when they are not installed system-wide. This might fall back
 * to the current workdir on some systems. Returns an empty string on
 * failure.
 *
 * @param dir - Output buffer
 * @param len - Output buffer size
 */
void os_get_executable_dir(char* dir, size_t len);

/**
 * Join multiple path segments with the right directory separator.
 * Version that accepts forarding variadic arguments of the caller.
 * 
 * @param out - Output buffer
 * @param len - Output buffer size
 * @param count - Number of path segments to join
 * @param segments - Path segments to join
 */
void os_path_join_v(char* out, size_t len, size_t count, va_list segments);

/**
 * Join multiple path segments with the right directory separator.
 * Regular version with variadic arguments.
 * 
 * @param out - Output buffer
 * @param len - Output buffer size
 * @param count - Number of path segments to join
 * @param ... - Path segments to join
 */
static void os_path_join(char* out, size_t len, size_t count, ...) {
    va_list segments;
    va_start(segments, count);
    os_path_join_v(out, len, count, segments);
    va_end(segments);
}

/**
 * Check if a file or directory exists.
 *
 * @param path - The path to check with OS-specific syntax
 * @returns true, if the path exists in the filesystem.
 */
bool os_path_exists(char* path);
