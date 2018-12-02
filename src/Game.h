#ifndef GAME_H
#define GAME_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "TextureManager.h"

class Game {

private:
	int cnt = 0;
	bool isRunning = false;
	SDL_Window *gWindow = nullptr;
public:

	Game();
	~Game();

	void init(const char *title, int x, int y, int w, int h,
                        bool fullscreen);
	void eventHandler();
	void update();
	void renderer();
	void clear();
        static SDL_Renderer *gRenderer;
	bool running();
};

#endif
