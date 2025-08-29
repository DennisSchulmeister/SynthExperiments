/* Csound native app - Minimal skeleton
 * (C) 2025 Dennis Schulmeister-Zimolong <dennis@windows3.de>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 */
#include "../os.h"

#include <stdio.h>      // snprintf
#include <string.h>     // strlen, strncat, strncpy
#include <windows.h>    // GetCurrentDirectoryA, GetModuleFileNameA, _splitpath_s, MAX_PATH, ...

/**
 * Get the current work directory of the process.
 */
void os_get_current_workdir(char* cwd, size_t len) {
    if (!cwd || len == 0) return;

    DWORD result = GetCurrentDirectoryA((DWORD)len, cwd);

    if (result == 0 || result >= len) {
        cwd[0] = '\0';
    }
}

/**
 * Get the directory of the process executable or fall back to the current workdir.
 */
void os_get_executable_dir(char* dir, size_t len) {
    if (!dir || len == 0) return;

    char path[MAX_PATH];
    DWORD result = GetModuleFileNameA(NULL, path, MAX_PATH);
    
    if (result == 0 || result == MAX_PATH) {
        os_get_current_workdir(dir, len);
        return;
    }

    // Remove the executable name from the path
    char drive[_MAX_DRIVE];
    char folder[_MAX_DIR];
    _splitpath_s(path, drive, sizeof(drive), folder, sizeof(folder), NULL, 0, NULL, 0);
    snprintf(dir, len, "%s%s", drive, folder);
}

/**
 * Join multiple path segments.
 */
void os_path_join_v(char* out, size_t len, size_t count, va_list segments) {
    if (!out || len == 0) return;

    out[0] = '\0';
    const char* segment;
    size_t used = 0;

    for (size_t i = 0; i < count; i++) {
        segment = va_arg(segments, const char*);
        if (segment[0] == '\0') continue;

        // Add a backslash if needed
        if (used > 0 && out[used - 1] != '\\') {
            if (used + 1 >= len) break;
            out[used++] = '\\';
            out[used] = '\0';
        }

        size_t seglen = strlen(segment);
        if (used + seglen >= len) break;

        strncat(out, segment, len - used - 1);
        used = strlen(out);
    }
}

/**
 * Check if a file or directory exists.
 */
bool os_path_exists(char* path) {
    DWORD attrs = GetFileAttributesA(path);
    return (attrs != INVALID_FILE_ATTRIBUTES);
}
