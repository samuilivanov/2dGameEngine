#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Game.h"
#include "TextureManager.h"

class GameObject {
private:
	SDL_Texture *objTexture;
	SDL_Renderer *render;
	int xPos;
	int yPos;
	SDL_Rect srcRect, dstRect;
public:
	GameObject(const char *filePath, SDL_Renderer *ren, int x, int y);
	~GameObject();
	void Update();
	void Render();
};
#endif
