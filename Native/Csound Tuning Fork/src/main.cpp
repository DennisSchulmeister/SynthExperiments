/* Csound native app - Tuning Fork
 * (C) 2025 Dennis Schulmeister-Zimolong <dennis@windows3.de>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 */
#include <csound/csound.hpp>            // Csound
#include <csound/csPerfThread.hpp>      // CsoundPerformanceThread
#include <filesystem>                   // std::filesystem
#include <iostream>                     // std::cout, std::cerr, std::endl

#include "assets.hpp"                   // my::assets

// TODO: Dear ImGUI
#include <imgui.h>
#include <imgui_impl_sdl2.h>
#include <imgui_impl_sdlrenderer2.h>
#include <SDL.h>

int main(int argc, char** argv) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER) != 0) {
        std::cerr << "SDL Error: " << SDL_GetError() << std::endl;
        return -1;
    }
      
    std::cout << "Searching assets..." << std::endl;

    auto csd_file = my::assets::get_path("assets/csound.csd");

    if (!csd_file) {
        std::cerr << "Cannot find file csound.csd" << std::endl;
        return -1;
    }
    
    std::cout << "Initializing Csound..." << std::endl;
    Csound* csound = new Csound();

    if (csound->Compile(csd_file->c_str()) != 0) {
        std::cerr << "Csound error" << std::endl;
        return -1;
    }
    
    std::cout << "Starting Csound performance..." << std::endl;
    CsoundPerformanceThread* performanceThread = new CsoundPerformanceThread(csound); 
    performanceThread->Play();
    while (performanceThread->GetStatus() == 0);

    std::cout << "Cleaning up..." << std::endl;
    delete performanceThread;
    delete csound;
    return 0;
}
