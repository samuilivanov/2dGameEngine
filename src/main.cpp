#include "Game.h"
#include <iostream>

int main(int argc, char **argv)
{
	const int SCREEN_FPS = 60;
	const int SCREEN_TICKS_PER_SECOND = 1000 / SCREEN_FPS;
	Uint32 frameStart;
	int frameTime;

	Game *game = new Game();
	game->init("Sambio 2D Game engine", SDL_WINDOWPOS_CENTERED,
                        SDL_WINDOWPOS_CENTERED, 800, 640, false);
	
	while (game->running()) {

		frameStart = SDL_GetTicks();

		game->eventHandler();
		game->update();
		game->renderer();
		
		frameTime = SDL_GetTicks() - frameStart;
		if (SCREEN_TICKS_PER_SECOND > frameTime) {
			SDL_Delay(SCREEN_TICKS_PER_SECOND - frameTime);
		}
	}

	game->clear();

	return 0;
}
