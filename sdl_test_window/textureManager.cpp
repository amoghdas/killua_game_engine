#include "textureManager.h"

SDL_Texture* TextureManager::loadTexture(const char* texture, SDL_Renderer* ren) {
	SDL_Surface* tempSurface = IMG_Load(texture);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tempSurface);
	SDL_FreeSurface(tempSurface);

	return tex;
}