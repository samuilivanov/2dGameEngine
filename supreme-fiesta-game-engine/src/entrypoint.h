#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H
#include "application.h"
#include "Utils/log.h"

extern SFGE::Application *SFGE::createApplication();

int main(int argc, char **argv)
{
    auto app = SFGE::createApplication();

    SFGE::Log::init();

    app->run();
    delete app;
    return 0;
}

#endif // ENTRYPOINT_H
