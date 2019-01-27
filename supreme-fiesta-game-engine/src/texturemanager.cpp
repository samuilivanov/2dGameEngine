#include "texturemanager.h"
#include "sfgepch.h"

namespace SFGE {

    SDL_Texture *TextureManager::loadTexture(const char *filePath) {
        SDL_Surface *tmpSurface = IMG_Load(filePath);
        if (tmpSurface == nullptr) {
            printf("Failed to load texture image!");
        }
        SDL_Texture *tmpTex = SDL_CreateTextureFromSurface(Application::gRenderer,
                                                             tmpSurface);
        SDL_FreeSurface(tmpSurface);
        return tmpTex;
    }

    void TextureManager::draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dst)
    {
            SDL_RenderCopy(Application::gRenderer, tex, &src, &dst);
    }

}
