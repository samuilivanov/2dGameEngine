#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Game.h"
#include "TextureManager.h"

class GameObject {
private:
	SDL_Texture *objTexture;
	int xPos;
	int yPos;
	SDL_Rect srcRect, dstRect;
public:
	GameObject(const char *filePath, int x, int y);
	~GameObject();
	void Update();
	void Render();
};
#endif
