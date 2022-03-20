#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texturesheet, SDL_Renderer *renderer, int x, int y) {
    this->renderer = renderer;

    texture = TextureManager::LoadTexture(texturesheet, renderer);

    xPos = x;
    yPos = y;
}

void GameObject::Update() {

    srcRect.h = 32;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xPos;
    destRect.y = yPos;
    destRect.w = srcRect.w * 2;
    destRect.h = srcRect.h * 2;
}

void GameObject::Render() {
    SDL_RenderCopy(renderer, texture, &srcRect, &destRect);
}
