#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include "../core.h"
#include "components.h"
#include "sfgepch.h"
#include "../application.h"
#include "src/texturemanager.h"

namespace SFGE {

    class SFGE_API SpriteComponent : public Component
    {
    private:
        TransformComponent *transform;
        SDL_Texture *texture;
        SDL_Rect srcRect;
        SDL_Rect destRect;
    public:
        SpriteComponent() = default;
        SpriteComponent(const char *path)
        {
            texture = TextureManager::loadTexture(path);
        }
        void init() override
        {
            transform = &entity->getComponent<TransformComponent>();
            srcRect.w = 600;
            srcRect.h = 600;
            srcRect.x = 0;
            srcRect.y = 0;

            destRect.w = srcRect.w / 9;
            destRect.h = srcRect.h / 9;
        }
        void update() override
        {
            destRect.x = static_cast<int>(transform->position.x);
            destRect.y = static_cast<int>(transform->position.y);
        }
        void draw() override
        {
            TextureManager::draw(texture, srcRect, destRect);
        }
    };
}

#endif // SPRITECOMPONENT_H
