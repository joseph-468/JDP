#pragma once

#include <functional>

class Widget {
public:
    Widget() = default;
    virtual ~Widget() = default;
    virtual void display() const = 0;

    int x{}, y{};
    int w{}, h{};
};

class Button final : public Widget {
public:
    Button();
    Button(int x, int y, int w, int h);
    void display() const override;

    std::function<void()> onPress;
    std::function<void()> onRelease;
};