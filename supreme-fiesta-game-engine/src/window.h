#ifndef WINDOW_H
#define WINDOW_H

#include "src/core.h"
#include "sfgepch.h"

namespace SFGE {

    class WindowProps
    {
    public:
        uint32_t width;
        uint32_t height;
        std::string title;

        // TODO : SDL2 does not accept std::string in the title
        WindowProps(uint32_t width = 1280, uint32_t height = 720, std::string title = "Supreme Fiesta Game Engine")
            : width(width), height(height), title(title){}
    };

    class SFGE_API Window
    {
    public:
        virtual ~Window() {}
        virtual void eventHandler() = 0;
        virtual void update() = 0;
        virtual void renderer() = 0;
        virtual bool running() = 0;
        virtual void shutdown() = 0;
        static Window *createWindow(const WindowProps &props = WindowProps());
    };
}

#endif // WINDOW_H
