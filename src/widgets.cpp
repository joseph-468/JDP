#include <raylib.h>

#include "widgets.h"

Button::Button(const int x, const int y, const int w, const int h) {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}

void Button::display() const {
    DrawRectangle(x, y, w, h, RED);
}