#include "linuxwindow.h"
#include "src/map.h"
#include "src/ECS/ecs.h"
#include "src/ECS/components.h"

namespace SFGE {

    SDL_Renderer *LinuxWindow::gRenderer = nullptr;
    SDL_Event LinuxWindow::event;
    Map *map;
    Manager manager;
    auto &player(manager.addEntity());

    Window* Window::createWindow(const WindowProps& props)
    {
        return new LinuxWindow(props);
    }

    LinuxWindow::LinuxWindow(const WindowProps &props)
    {
        init(props);
    }

    LinuxWindow::~LinuxWindow()
    {

    }

    void LinuxWindow::init(const WindowProps &props)
    {

        if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
            SFGE_CORE_FATAL("SDL could not initialize! SDL_Error: ");
            // TODO: I want the SDL_GetError msg to print **** std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError();
            isRunning = false;
        } else {
            SFGE_CORE_INFO("SDL initialized...");

            // TODO it should not be hard coded for now is OK
            gWindow = SDL_CreateWindow("Supreme Fiesta Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, props.width, props.height, false);
            if (gWindow == nullptr) {
                SFGE_CORE_FATAL("Window could not be created! SDL_Error: ");
                //std::cout << "Window could not be created! SDL_Error: " << SDL_GetError();
                isRunning = false;
            } else {
                SFGE_CORE_INFO("Window created successfully!");
                gRenderer = SDL_CreateRenderer(gWindow, -1, 0);
                if (gRenderer) {
                    SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
                    SFGE_CORE_INFO("Renderer created successfully!");
                }
                isRunning = true;
            }
        }
        map = new Map();
        player.addComponent<TransformComponent>();
        player.addComponent<SpriteComponent>("/home/samuil/projects/supreme-fiesta-game-engine/assets/player.png");
        player.addComponent<KeyBoardController>();
    }

    // TODO: This should be a separete class
    void LinuxWindow::eventHandler()
    {
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT) {
            isRunning = false;
        }
    }

    void LinuxWindow::update()
    {
        manager.refresh();
        manager.update();
    }

    // TODO: At some point this should be a separete class
    void LinuxWindow::renderer()
    {
        SDL_RenderClear(gRenderer);
        map->drawMap();
        manager.draw();
        SDL_RenderPresent(gRenderer);
    }

    bool LinuxWindow::running()
    {
        return isRunning;
    }

    void LinuxWindow::shutdown()
    {
        SDL_DestroyWindow(gWindow);
        SDL_DestroyRenderer(gRenderer);
        SDL_Quit();
        SFGE_CORE_INFO("Game cleaned!");
    }
}
