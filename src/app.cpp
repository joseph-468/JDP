#include <raylib.h>
#include <iostream>

#include "app.h"
#include "widgets.h"

constexpr double WINDOW_SIZE_PERCENTAGE = 2.0 / 3.0; // Percentage of the monitor that the window will take up by default.

App::App() : running(false), windowWidth(0), windowHeight(0) {}

void App::run() {
    InitWindow(1, 1, "JDP");
    const int currentMonitor = GetCurrentMonitor();
    const int monitorWidth = GetMonitorWidth(currentMonitor);
    const int monitorHeight = GetMonitorHeight(currentMonitor);
    windowWidth = static_cast<int>(monitorWidth * WINDOW_SIZE_PERCENTAGE);
    windowHeight = static_cast<int>(monitorHeight * WINDOW_SIZE_PERCENTAGE);
    SetWindowSize(windowWidth, windowHeight);
    SetWindowPosition(monitorWidth / 2 - windowWidth / 2, monitorHeight / 2 - windowHeight / 2);
    running = true;

    while (!WindowShouldClose()) {
        update();
        render();
    }

    CloseWindow();
    running = false;
}

void App::update() {
}

void App::render() {
    BeginDrawing();
    ClearBackground(WHITE);
    testWidget.display();
    EndDrawing();
}
