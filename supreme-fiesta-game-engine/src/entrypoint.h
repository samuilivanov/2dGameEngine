#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H
#include "application.h"

extern SFGE::Application *SFGE::createApplication();

int main(int argc, char **argv)
{
    auto app = SFGE::createApplication();
    app->init();
    app->run();
    delete app;
    return 0;
}

#endif // ENTRYPOINT_H
