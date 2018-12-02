#include "TextureManager.h"

SDL_Texture *TextureManager::loadTexture(const char *filePath) {
	SDL_Surface *tmpSurface = IMG_Load(filePath);
	if (tmpSurface == nullptr) {
		printf("Failed to load texture image!");
	}
	SDL_Texture *tmpTex = SDL_CreateTextureFromSurface(Game::gRenderer,
                                                         tmpSurface);
	SDL_FreeSurface(tmpSurface);
	return tmpTex;
}

void TextureManager::Draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dst)
{
        SDL_RenderCopy(Game::gRenderer, tex, &src, &dst);
}
