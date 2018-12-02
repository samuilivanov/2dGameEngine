#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char *filePath, int x, int y) {
	objTexture = TextureManager::loadTexture(filePath);
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
}

void GameObject::Render() {
	SDL_RenderCopy(Game::gRenderer, objTexture, &srcRect, &dstRect);
}
