#pragma once

class App {
public:
    App();
    ~App();
    void run();

private:
    void update();
    void render();

    int windowWidth;
    int windowHeight;
};