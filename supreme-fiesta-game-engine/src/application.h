#ifndef APPLICATION_H
#define APPLICATION_H

#include "src/core.h"
#include "Utils/log.h"
#include "src/window.h"
#include <SDL2/SDL.h>

namespace SFGE {

    class SFGE_API Application
    {
    private:
        std::unique_ptr<Window> m_Window;
    public:

        Application();
        ~Application();

        void run();
        // TODO: event methods to be added as well with event class

    };

    Application *createApplication();
}

#endif // APPLICATION_H
