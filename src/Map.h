#ifndef MAP_H
#define MAP_H
#include "Game.h"

class Map
{
private:
        SDL_Texture *grassTex;
        SDL_Texture *dirtTex;
        SDL_Texture *waterTex;
        int map[20][25]; 
        SDL_Rect src;
        SDL_Rect dst;
public:
        Map();
        ~Map();

        void LoadMap();
        void DrawMap();
};

#endif
