#include "Game.h"
#include <stdio.h>
#include <iostream>

// Constructor and deconstructor
Game::Game() {
}

Game::~Game() {
}

// Start up SDL and subsistems
void Game::init(const char *title, int x, int y, int w, int h, bool fullscreen) {
	int flag = 0;
	if (fullscreen) { flag = 1; }

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		isRunning = false;
	} else {
		printf("SDL initialized...\n");

		gWindow = SDL_CreateWindow(title, x, y, w, h, flag);
		if (gWindow == nullptr) {
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			isRunning = false;
		} else {
			printf("Window created successfully!\n");

			gRenderer = SDL_CreateRenderer(gWindow, -1, 0);
			if (gRenderer) {
				SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 255);
				printf("Renderer created successfully!\n");
			}
			isRunning = true;
		}
	}
}

void Game::eventHandler() {
	SDL_Event event;
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT) {
		isRunning = false;
	}
}

void Game::update() {
	cnt++;
	std::cout << cnt << std::endl;
}

void Game::renderer() {
	SDL_RenderClear(gRenderer);
	SDL_RenderPresent(gRenderer);
}

void Game::clear() {
	SDL_DestroyWindow(gWindow);
	SDL_DestroyRenderer(gRenderer);
	SDL_Quit();
	printf("Game cleaned!\n");
}

bool Game::running() {
	return isRunning;
}
