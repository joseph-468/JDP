#include "app.h"

#if defined(WIN32) && defined(NDEBUG)
#define main WinMain
#endif

int main(int argc, char *argv[]) {
    App app;
    app.run();
}
