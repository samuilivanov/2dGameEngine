#include "TextureManager.h"

SDL_Texture *TextureManager::loadTexture(const char *filePath, SDL_Renderer *ren) {
	SDL_Surface *tmpSurface = IMG_Load(filePath);
	if (tmpSurface == nullptr) {
		printf("Failed to load texture image!");
	}
	SDL_Texture *tmpTex = SDL_CreateTextureFromSurface(ren, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	return tmpTex;
}
