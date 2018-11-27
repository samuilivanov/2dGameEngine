#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SDL2/SDL_image.h>

class TextureManager {
public:
	static SDL_Texture *loadTexture(const char *filePath, SDL_Renderer *ren);
};

#endif
