#include "gameObject.h"
#include "textureManager.h"

GameObject::GameObject(const char* texturesheet, SDL_Renderer* ren, int x, int y) {
	renderer_ = ren;
	objTexture_ = TextureManager::loadTexture(texturesheet, ren);
	
	xpos = x;
	ypos = y;
}

void GameObject::update() {
	xpos++;
	ypos++;

	srcRect_.h = 32;
	srcRect_.w = 32;
	srcRect_.x = 0;
	srcRect_.y = 0;

	destRect_.x = xpos;
	destRect_.y = ypos;
	destRect_.w = srcRect_.w * 2;
	destRect_.h = srcRect_.h * 2;

}

void GameObject::render() {
	SDL_RenderCopy(renderer_, objTexture_, &srcRect_, &destRect_);

}


