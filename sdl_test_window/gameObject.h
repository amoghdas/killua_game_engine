#pragma once
#include "game.h"

class GameObject {
public:
	GameObject(const char* texturesheet, SDL_Renderer* ren, int x, int y);
	~GameObject();

	void update();
	void render();

private:
	int xpos;
	int ypos;

	SDL_Texture* objTexture_;
	SDL_Rect srcRect_, destRect_;
	SDL_Renderer* renderer_;


};