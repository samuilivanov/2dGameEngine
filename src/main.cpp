#include "Game.h"
#include <iostream>

int main() {
	Game *game = new Game();
	game->init("Sambio 2D Game engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		800, 600, false);
	
	while (game->running()) {
		game->eventHandler();
		game->update();
		game->renderer();
	}

	game->clear();

	return 0;
}
