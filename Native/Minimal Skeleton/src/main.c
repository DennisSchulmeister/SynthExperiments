/*
 * libcsound example from the doxygen documentation
 */
#include <stdio.h>
#include <csound.h>
#include "config.h"

const char *csd_text =
    "<CsoundSynthesizer>\n"
    "<CsOptions>\n"
    "    -odac\n"
    "    --realtime\n"
    "</CsOptions>\n"
    "<CsInstruments>\n"
    "sr = 22050\n"
    "ksmps  = 256\n"
    "nchnls = 2\n"
    "0dbfs  = 1\n"
    "    instr 1\n"
    "        out(linen(oscili(p4, p5), 0.1, p3, 0.1))\n"
    "    endin\n"
    "</CsInstruments>\n"
    "<CsScore>\n"
    "    t 0 60\n"
    "    i1 0 5 .75 440\n"
    "</CsScore>\n"
    "</CsoundSynthesizer>\n";

int main(int argc, char** argv) {
    printf("Asset path: %s\n", ASSET_PATH);

    void *csound = csoundCreate(0);
    int result = csoundCompileCsdText(csound, csd_text);

    result = csoundStart(csound);
    
    while (1) {
        result = csoundPerformKsmps(csound);
        if (result != 0) break;
    }
    
    result = csoundCleanup(csound);
    csoundReset(csound);
    csoundDestroy(csound);
    return result;
}
