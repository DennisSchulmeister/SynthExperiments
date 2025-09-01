/* Csound native app - Tuning Fork
 * (C) 2025 Dennis Schulmeister-Zimolong <dennis@windows3.de>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 */
#include "ui.hpp"

#include <csound/csound.hpp>            // Csound
#include <csound/csPerfThread.hpp>      // CsoundPerformanceThread
#include <filesystem>                   // std::filesystem
#include <iostream>                     // std::cout, std::endl

#include "assets.hpp"                   // my::assets

namespace my::ui {

Csound* csound = nullptr;
CsoundPerformanceThread* performanceThread = nullptr;

/**
 * Set up ressources like Csound.
 */
void setup(my::common::ui_context ctx) {
    std::cout << "Searching assets..." << std::endl;

    auto csd_file = my::assets::get_path("assets/csound.csd");

    if (!csd_file) {
        throw my::common::fatal_error("Cannot find file csound.csd");
    }
    
    std::cout << "Initializing Csound..." << std::endl;
    csound = new Csound();

    if (csound->Compile(csd_file->c_str()) != 0) {
        throw my::common::fatal_error("Error while compiling the Csound code");
    }
    
    std::cout << "Starting Csound performance..." << std::endl;
    performanceThread = new CsoundPerformanceThread(csound); 
    performanceThread->Play();

    // while (performanceThread->GetStatus() == 0);
}

/**
 * Perform user interface logic.
 */
my::common::main_loop_action execute(my::common::ui_context ctx) {
    // TODO
    return my::common::main_loop_action::keep_running;
}

/**
 * Clean up ressources.
 */
void cleanup() {
    delete performanceThread;
    delete csound;
}

} // namespace my::ui
