#include <raylib.h>

#include "app.h"

void App::run() {
    InitWindow(800, 450, "Window");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }

    CloseWindow();
}