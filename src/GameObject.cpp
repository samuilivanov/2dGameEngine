#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char *filePath, SDL_Renderer *ren, int x, int y) {
	render = ren;
	objTexture = TextureManager::loadTexture(filePath, render);
	xPos = x;
	yPos = y;
}

void GameObject::Update() {
	xPos++;
	yPos++;

	srcRect.w = 600;
	srcRect.h = 600;
	srcRect.x = 0;
	srcRect.y = 0;

	dstRect.w = srcRect.w / 9;
	dstRect.h = srcRect.h / 9;
	dstRect.x = xPos; 
	dstRect.y = yPos;
	/*srcRect.x = 300;
	srcRect.y = 300;
	srcRect.w = 32;
	srcRect.h = 32;

	dstRect.x = 640 / 2;
	dstRect.y = 640 / 2;
	dstRect.w = 32;
	dstRect.h = 32;*/
}

void GameObject::Render() {
	SDL_RenderCopy(render, objTexture, &srcRect, &dstRect);
}
