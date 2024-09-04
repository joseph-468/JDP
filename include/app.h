#pragma once

#include "widgets.h"

class App {
public:
    App();
    void run();

private:
    void update();
    void render();

    bool running;
    int windowWidth;
    int windowHeight;

    Button testWidget{0, 0, 50, 50};
};