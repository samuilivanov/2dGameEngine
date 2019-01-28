#ifndef APPLICATION_H
#define APPLICATION_H

#include "core.h"
#include "log.h"
#include <SDL2/SDL.h>

namespace SFGE {

    class SFGE_API Application
    {
    private:
        bool isRunning = false;
        SDL_Window *gWindow;
    public:

        Application();
        ~Application();

        static SDL_Renderer *gRenderer;
        static SDL_Event event;

        void init();
        void run();
        void eventHandler();
        void update();
        void renderer();
        void clear();
        bool running();
    };

    Application *createApplication();
}

#endif // APPLICATION_H
