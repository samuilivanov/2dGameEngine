#include "sfgepch.h"
#include "application.h"
#include "map.h"
#include "ECS/ecs.h"
#include "src/ECS/components.h"
#include <QMessageLogger>

namespace SFGE {

    Application::Application()
    {
        SFGE_CORE_INFO("App created");
        m_Window = std::unique_ptr<Window>(Window::createWindow());
    }

    Application::~Application()
    {
        SFGE_CORE_INFO("App killed");
    }

    void Application::run()
    {
        const int SCREEN_FPS = 60;
        const int SCREEN_TICKS_PER_SECOND = 1000 / SCREEN_FPS;
        Uint32 frameStart;
        int frameTime;

        while (m_Window->running()) {

            frameStart = SDL_GetTicks();

            m_Window->update();
            m_Window->eventHandler();
            m_Window->renderer();

            frameTime = SDL_GetTicks() - frameStart;
            if (SCREEN_TICKS_PER_SECOND > frameTime) {
                SDL_Delay(SCREEN_TICKS_PER_SECOND - frameTime);
            }
        }
        m_Window->shutdown();
    }

}
