#include "game.h"
#include <iostream>

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
	std::cout << count_ << '\n';
}

void Game::render() {
	SDL_RenderClear(renderer_);
	// this is where we would add stuff to render
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
