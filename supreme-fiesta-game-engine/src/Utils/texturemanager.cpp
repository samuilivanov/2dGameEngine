#include "texturemanager.h"
#include "src/Platform/Linux/linuxwindow.h"
#include "sfgepch.h"

namespace SFGE {

    SDL_Texture *TextureManager::loadTexture(const char *filePath) {
        SDL_Surface *tmpSurface = IMG_Load(filePath);
        if (tmpSurface == nullptr) {
            printf("Failed to load texture image!");
        }
        SDL_Texture *tmpTex = SDL_CreateTextureFromSurface(LinuxWindow::gRenderer,
                                                             tmpSurface);
        SDL_FreeSurface(tmpSurface);
        return tmpTex;
    }

    void TextureManager::draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dst)
    {
            SDL_RenderCopy(LinuxWindow::gRenderer, tex, &src, &dst);
    }

}
