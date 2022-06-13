#include "game.h"
#include <iostream>

SDL_Texture *playerTex;
SDL_Rect srcR, destR;

Game::Game() {
}

Game::~Game() {
}

void Game::init(const std::string title, int xpos, int ypos,
	int width, int height, bool fullscreen) {
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems initialized!...\n";
		window_ = SDL_CreateWindow(title.c_str(), xpos, ypos, width, height, flags);
		if (window_) {
			std::cout << "Window created!\n";
		}

		renderer_ = SDL_CreateRenderer(window_, -1, 0);
		if (renderer_) {
			SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255); // White
			std::cout << "Renderer created!\n";
		}

		isRunning_ = true;
	}
	else {
		isRunning_ = false;
	}

	SDL_Surface* tempSurface = IMG_Load("assets/player.png");
	playerTex = SDL_CreateTextureFromSurface(renderer_, tempSurface);
	SDL_FreeSurface(tempSurface);
}

void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning_ = false;
		break;

	default:
		break;
	}
}

void Game::update() {
	count_++;
	destR.h = 256;
	destR.w = 256;
	destR.x = count_;

	std::cout << count_ << '\n';
}

void Game::render() {
	SDL_RenderClear(renderer_);
	SDL_RenderCopy(renderer_, playerTex, NULL, &destR);
	SDL_RenderPresent(renderer_);
}

void Game::clean() {
	SDL_DestroyWindow(window_);
	SDL_DestroyRenderer(renderer_);
	SDL_Quit();
	std::cout << "Game cleaned\n";
}

bool Game::running() {
	return isRunning_;
}
