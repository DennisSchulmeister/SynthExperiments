/*
 * libcsound example from the doxygen documentation
 */
#include <csound/csound.hpp>
#include <csound/csPerfThread.hpp>
#include <iostream>

#include "config.h"

using namespace std;

int main(int argc, char** argv) {
    std::cout << "Asset Path: " << ASSET_PATH << std::endl;
    
    Csound* csound = new Csound();
    // TODO: System-specific path, platform-neutral path building
    csound->Compile("assets/csound.csd");
    
    CsoundPerformanceThread* performanceThread = new CsoundPerformanceThread(csound); 
    performanceThread->Play();
    
    while (performanceThread->GetStatus() == 0);
    
    delete performanceThread;
    delete csound;
    return 0;
}
