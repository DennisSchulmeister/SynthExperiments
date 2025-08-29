/* Csound native app - Minimal skeleton
 * (C) 2025 Dennis Schulmeister-Zimolong <dennis@windows3.de>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 */
#include <stdio.h>      // perror
#include <csound.h>     // Csound...
#include <limits.h>     // PATH_MAX

#include "assets.h"     // assets_...

int main(int argc, char** argv) {
    printf("Searching assets ...\n");
    char csd_file[PATH_MAX];

    assets_init();

    if (!assets_get_path(csd_file, PATH_MAX, "assets", "csound.csd", NULL)) {
        perror("Cannot find file csound.csd");
        return -1;
    }

    printf("Initializing Csound ...\n");
    void *csound = csoundCreate(0);
    if (csoundCompileCsd(csound, csd_file) != 0) goto csoundError;
    if (csoundStart(csound)) goto csoundError;

    printf("Starting Csound performance ...\n");
    while (1) {
        if (csoundPerformKsmps(csound) != 0) break;
    }

    printf("Cleaning up ...");
    if (csoundCleanup(csound) != 0) goto csoundError;
    csoundReset(csound);
    csoundDestroy(csound);
    return 0;

    csoundError:
        perror("Csound error");
        return -1;
}
