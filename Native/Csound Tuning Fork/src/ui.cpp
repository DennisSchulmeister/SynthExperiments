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

void mainScreen(const my::common::ui_context& ctx, ImGuiViewport* viewport);
void settingsScreen(const my::common::ui_context& ctx, ImGuiViewport* viewport);
void logsScreen(const my::common::ui_context& ctx, ImGuiViewport* viewport);

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
            mainScreen(ctx, viewport);
            ImGui::EndTabItem();
        }

        if (ImGui::BeginTabItem("Settings")) {
            settingsScreen(ctx, viewport);
            ImGui::EndTabItem();
        }

        if (ImGui::BeginTabItem("Logs")) {
            logsScreen(ctx, viewport);
            ImGui::EndTabItem();
        }

        ImGui::EndTabBar();
    }

    ImGui::End();

    return my::common::main_loop_action::keep_running;
}

/**
 * Main screen with the (very sophisticated) synthesizer controls.
 */
void mainScreen(const my::common::ui_context& ctx, ImGuiViewport* viewport) {
    ImVec2 window_size = viewport->Size;
    ImVec2 item_spacing = ImGui::GetStyle().ItemSpacing;

    // Big bold label
    ImGui::PushFont(ctx.font.heading);

    const char* title = "Tuning Fork";
    ImVec4 title_color = ImVec4{0.13f, 0.6f, 0.82f, 1.0f};
    ImVec2 title_size = ImGui::CalcTextSize(title);
    ImGui::SetCursorPosX((window_size.x - title_size.x) * 0.5f);

    ImGui::TextColored(title_color, "%s", title);
    ImGui::PopFont();

    float title_bottom = ImGui::GetCursorPosY();

    // Status message
    const char* status_text = "Csound stopped - Please restart it on the settings page!";
    ImVec4 status_color{0.66f, 0.66f, 0.0f, 1.0f};

    if (performanceThread != nullptr) {
        int status = performanceThread->GetStatus();

        if (status == 0) {
            status_text = "Csound is running - You are good to go.";
            status_color = ImVec4{0.0f, 0.66f, 0.0f, 1.0f};
        } else if (status < 0) {
            status_text = "Csound reported an error - Please try to restart it on the settings page!";
            status_color = ImVec4{0.0f, 0.66f, 0.0f, 1.0f};
        }
    }

    ImGui::PushFont(ctx.font.status);
    ImVec2 status_size = ImGui::CalcTextSize(status_text);
    ImGui::SetCursorPosY(window_size.y - status_size.y - item_spacing.y);
    ImGui::TextColored(status_color, "%s", status_text);
    ImGui::PopFont();

    // Button to trigger the sound
    ImVec2 button_size{140, 40};

    ImGui::SetCursorPos(ImVec2{
        (window_size.x - button_size.x) * 0.5f,
        title_bottom + (window_size.y - button_size.y - title_bottom - item_spacing.y - status_size.y - item_spacing.y) * 0.5f
    });

    if (ImGui::Button("Bing!", button_size) && csound != nullptr) {
        csound->SetControlChannel("trigger", 1);
    } else if (csound != nullptr) {
        csound->SetControlChannel("trigger", 0);
    }
}

/**
 * Audio settings screen to configure and start/stop Csound.
 */
void settingsScreen(const my::common::ui_context& ctx, ImGuiViewport* viewport) {
    if (ImGui::Button("Restart Csound")) startCsound();
    ImGui::Text("TODO - Csound options");
}

/**
 * Log screen to display the Csound console outputs.
 */
void logsScreen(const my::common::ui_context& ctx, ImGuiViewport* viewport) {
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
