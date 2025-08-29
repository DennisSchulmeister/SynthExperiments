/* Csound native app - Minimal skeleton
 * (C) 2025 Dennis Schulmeister-Zimolong <dennis@windows3.de>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 */
#include "../os.h"

#include <libgen.h>         // dirn ame
#include <limits.h>         // PATH_MAX
#include <stdlib.h>         // realpath
#include <string.h>         // strlen, strncat, strncpy
#include <unistd.h>         // getcwd
#include <sys/stat.h>       // stat

/**
 * Get the current work directory of the process.
 */
void os_get_current_workdir(char* cwd, size_t len) {
    if (!cwd || len == 0) return;

    if (getcwd(cwd, len) == NULL) {
        cwd[0] = '\0';
    }
}

/**
 * Get the directory of the process executable or fall back to the current workdir.
 */
void os_get_executable_dir(char* dir, size_t len) {
    if (!dir || len == 0) return;

    // On Linux we can simply resolve /proc/self/exe. On systems where
    // this is not available (typically BSD) we fallback to the workdir.
    char resolved[PATH_MAX];
    
    if (realpath("/proc/self/exe", resolved) == NULL) {
        os_get_current_workdir(dir, len);
        return;
    }

    // Get directory part
    char* dirpath = dirname(resolved);
    strncpy(dir, dirpath, len - 1);
    dir[len - 1] = '\0';
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

        // Add slash if needed
        if (used > 0 && out[used - 1] != '/') {
            if (used + 1 >= len) break;
            out[used++] = '/';
            out[used] = '\0';
        }

        size_t seglen = strlen(segment);
        if (used + seglen >= len) break;

        strncat(out, segment, len - used - 1);
        used = strlen(out);
    }
}

/**
 * Check if a file or directory exists (following symlinks).
 */
bool os_path_exists(char* path) {
    struct stat st;
    return stat(path, &st) == 0;
}
