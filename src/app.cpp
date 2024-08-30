#include <raylib.h>
#include <iostream>

#include "app.h"

constexpr double WINDOW_SIZE_PERCENTAGE = 2.0 / 3.0; // Percentage of the monitor that the window will take up by default.

App::App() {
    InitWindow(1, 1, "JDP");
    const int currentMonitor = GetCurrentMonitor();
    const int monitorWidth = GetMonitorWidth(currentMonitor);
    const int monitorHeight = GetMonitorHeight(currentMonitor);
    windowWidth = static_cast<int>(monitorWidth * WINDOW_SIZE_PERCENTAGE);
    windowHeight = static_cast<int>(monitorHeight * WINDOW_SIZE_PERCENTAGE);
    SetWindowSize(windowWidth, windowHeight);
    SetWindowPosition(monitorWidth / 2 - windowWidth / 2, monitorHeight / 2 - windowHeight / 2);
}

App::~App() {
    CloseWindow();
}

void App::update() {
    Vector2 const mousePos = GetMousePosition();
    std::cout << "Mouse X: " << mousePos.x << " Mouse Y: " << mousePos.y << std::endl;
}

void App::render() {
    BeginDrawing();
    ClearBackground(WHITE);
    EndDrawing();
}

void App::run() {
    while (!WindowShouldClose()) {
        update();
        render();
    }
}