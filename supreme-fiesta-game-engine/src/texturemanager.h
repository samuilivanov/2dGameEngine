#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "core.h"
#include "application.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

namespace SFGE {

    class SFGE_API TextureManager {
    public:
        static SDL_Texture *loadTexture(const char *filePath);
        static void draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dst);
    };

}
#endif // TEXTUREMANAGER_H
