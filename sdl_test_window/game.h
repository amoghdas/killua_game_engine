#pragma once
#include "SDL.h"
#include <string>

class Game {
public:
	Game();
	~Game();

	void init(const std::string title, int xpos, int ypos,
		int width, int height, bool fullscreen);
	
	void handleEvents();
	void update();
	void render();
	void clean();
	bool running();

private:
	int count_ = 0;
	bool isRunning_;
	SDL_Window* window_;
	SDL_Renderer* renderer_;
};

