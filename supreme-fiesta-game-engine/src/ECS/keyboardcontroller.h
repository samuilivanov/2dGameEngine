#include "../application.h"
#include "ecs.h"
#include "components.h"
#include "../core.h"

namespace SFGE {

    class SFGE_API KeyBoardController : public Component
    {
    public:
        TransformComponent *transform;

        void init() override
        {
            transform = &entity->getComponent<TransformComponent>();
        }

        void update() override
        {
            if (Application::event.type == SDL_KEYDOWN) {
                switch (Application::event.key.keysym.sym) {
                case SDLK_w:
                    transform->velocity.y = -1;
                    break;
                case SDLK_a:
                    transform->velocity.x = -1;
                    break;
                case SDLK_s:
                    transform->velocity.y = 1;
                    break;
                case SDLK_d:
                    transform->velocity.x = 1;
                    break;
                }
            }

            if (Application::event.type == SDL_KEYUP) {
                switch (Application::event.key.keysym.sym) {
                case SDLK_w:
                    transform->velocity.y = 0;
                    break;
                case SDLK_a:
                    transform->velocity.x = 0;
                    break;
                case SDLK_s:
                    transform->velocity.y = 0;
                    break;
                case SDLK_d:
                    transform->velocity.x = 0;
                    break;
                }
            }
        }
    };
}
