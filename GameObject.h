#ifndef INC_2DGAMEENGINE_GAMEOBJECT_H
#define INC_2DGAMEENGINE_GAMEOBJECT_H

#include <SDL.h>

class GameObject{

public:
    GameObject(const char* texturesheet, SDL_Renderer* renderer, int x = 0, int y = 0);
    ~GameObject();

    void Update();
    void Render();

private:
    int xPos, yPos;

    SDL_Texture* texture;
    SDL_Rect srcRect, destRect;
    SDL_Renderer* renderer;

};

#endif //INC_2DGAMEENGINE_GAMEOBJECT_H
