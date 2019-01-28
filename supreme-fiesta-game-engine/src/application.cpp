#include "sfgepch.h"
#include "application.h"
#include "map.h"
#include "ECS/ecs.h"
#include "ECS/components.h"
#include <QMessageLogger>

namespace SFGE {

    SDL_Renderer *Application::gRenderer = nullptr;
    SDL_Event Application::event;
    Map *map;
    Manager manager;
    auto &player(manager.addEntity());

    Application::Application()
    {
        SFGE_CORE_INFO("App created");
    }
    Application::~Application()
    {
        SFGE_CORE_INFO("App killed");
    }

    // TODO want to move this init() in separete class
    void Application::init()
    {
        if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
            SFGE_CORE_FATAL("SDL could not initialize! SDL_Error: ");
            // TODO: I want the SDL_GetError msg to print **** std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError();
            isRunning = false;
        } else {
            SFGE_CORE_INFO("SDL initialized...");

            // TODO it should not be hard coded for now is OK
            gWindow = SDL_CreateWindow("Sambio 2D Game engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
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


    void Application::run()
    {
        const int SCREEN_FPS = 60;
        const int SCREEN_TICKS_PER_SECOND = 1000 / SCREEN_FPS;
        Uint32 frameStart;
        int frameTime;

        while (running()) {

            frameStart = SDL_GetTicks();

            eventHandler();
            update();
            renderer();

            frameTime = SDL_GetTicks() - frameStart;
            if (SCREEN_TICKS_PER_SECOND > frameTime) {
                SDL_Delay(SCREEN_TICKS_PER_SECOND - frameTime);
            }
        }
        clear();
    }

    void Application::eventHandler() {
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT) {
            isRunning = false;
        }
    }

    void Application::update() {
        manager.refresh();
        manager.update();
    }

    void Application::renderer() {
        SDL_RenderClear(gRenderer);
        map->drawMap();
        manager.draw();
        SDL_RenderPresent(gRenderer);
    }

    void Application::clear() {
        SDL_DestroyWindow(gWindow);
        SDL_DestroyRenderer(gRenderer);
        SDL_Quit();
        SFGE_CORE_INFO("Game cleaned!");
    }

    bool Application::running() {
        return isRunning;
    }

}
