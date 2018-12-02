#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SDL2/SDL_image.h>
#include "Game.h"

class TextureManager {
public:
	static SDL_Texture *loadTexture(const char *filePath);
        static void Draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dst);
};

#endif
