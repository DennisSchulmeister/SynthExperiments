/* Csound native app - Minimal skeleton
 * (C) 2025 Dennis Schulmeister-Zimolong <dennis@windows3.de>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 */
#include "assets.h"

#include <limits.h>     // PATH_MAX
#include <stdarg.h>     // va_list, va_start, va_arg, va_end

#include "config.h"     // ASSET_PATH
#include "os.h"         // os_...

char executable_dir[PATH_MAX];

/**
 * Find executable path on start-up.
 */
void assets_init() {
    os_get_executable_dir(executable_dir, sizeof(executable_dir) / sizeof(char));
}

/**
 * Get path of an asset file or return false, if not found.
 */
bool assets_get_path(char* out, size_t len, ...) {
    va_list args;
    va_start(args, len);
    bool result = true;
    
    char filename[len];
    os_path_join_v(filename, len, args);

    os_path_join(out, len, executable_dir, filename, NULL);
    if (os_path_exists(out)) goto finish; 

    os_path_join(out, len, ASSET_PATH, filename, NULL);
    if (os_path_exists(out)) goto finish; 

    result = false;
    
    finish:
        va_end(args);
        return result;
}
