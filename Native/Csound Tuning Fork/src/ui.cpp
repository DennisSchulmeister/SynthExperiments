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

void mainScreen();
void settingsScreen();
void logsScreen();
void startCsound();
void stopCsound();

/**
 * Set up ressources.
 */
void setup(const my::common::ui_context& ctx) {
}

/**
 * Perform user interface logic.
 */
my::common::main_loop_action execute(const my::common::ui_context& ctx) {
    ImGuiViewport* viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(viewport->Pos);
    ImGui::SetNextWindowSize(viewport->Size);

    ImGui::Begin("Main Window", nullptr,
        ImGuiWindowFlags_NoDecoration |
        ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoSavedSettings |
        ImGuiWindowFlags_NoBringToFrontOnFocus |
        ImGuiWindowFlags_NoBackground
    );

    if (ImGui::BeginTabBar("Main Tab Bar", ImGuiTabBarFlags_None)) {
        if (ImGui::BeginTabItem("Main")) {
            mainScreen();
            ImGui::EndTabItem();
        }

        if (ImGui::BeginTabItem("Settings")) {
            settingsScreen();
            ImGui::EndTabItem();
        }

        if (ImGui::BeginTabItem("Logs")) {
            logsScreen();
            ImGui::EndTabItem();
        }

        ImGui::EndTabBar();
    }

    ImGui::End();

    // TODO
    return my::common::main_loop_action::keep_running;
}

/**
 * Main screen with the (veru sophisticated) synthesizer controls.
 */
void mainScreen() {
    ImGui::Text("TODO - Main Screen");
}

/**
 * Audio settings screen to configure and start/stop Csound.
 */
void settingsScreen() {
    ImGui::Text("TODO - Csound options");
}

/**
 * Log screen to display the Csound console outputs.
 */
void logsScreen() {
    ImGui::Text("TODO - Csound logs");
}

/**
 * Clean up ressources.
 */
void cleanup() {
    stopCsound();
}

/**
 * Restart the Csound engine.
 */
void startCsound() {
    stopCsound();

    auto csd_file = my::assets::get_path("assets/csound.csd");

    if (!csd_file) {
        throw my::common::fatal_error("Cannot find file csound.csd");
    }

    csound = new Csound();

    if (csound->Compile(csd_file->c_str()) != 0) {
        throw my::common::fatal_error("Error while compiling the Csound code");
    }

    performanceThread = new CsoundPerformanceThread(csound);
    performanceThread->Play();

    // while (performanceThread->GetStatus() == 0);
}

/**
 * Stop Csound and free all its ressources.
 */
void stopCsound() {
    if (performanceThread != nullptr) {
        performanceThread->Stop();
        performanceThread->Join();

        delete performanceThread;
        performanceThread = nullptr;
    }

    if (csound != nullptr) {
        delete csound;
        csound = nullptr;
    }
}

} // namespace my::ui
