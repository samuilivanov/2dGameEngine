#ifndef LINUXWINDOW_H
#define LINUXWINDOW_H

#include "src/window.h"
#include "sfgepch.h"
#include "src/Utils/log.h"
#include <SDL2/SDL.h>
#include <string>

namespace SFGE {

    class LinuxWindow : public Window
    {
    private:
        bool isRunning = false;
        SDL_Window *gWindow;
    public:
        //TODO : some of these methods will be moved to other classes
        static SDL_Renderer *gRenderer;
        static SDL_Event event;
        LinuxWindow(const WindowProps &props);
        virtual ~LinuxWindow();
        void init(const WindowProps &props);
        void shutdown() override;
        void eventHandler() override;
        void update() override;
        void renderer() override;
        bool running() override;
    };
}

#endif // LINUXWINDOW_H
