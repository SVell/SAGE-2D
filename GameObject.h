#ifndef INC_2DGAMEENGINE_GAMEOBJECT_H
#define INC_2DGAMEENGINE_GAMEOBJECT_H

#include "Game.h"

class GameObject{

public:
    GameObject(const char* texturesheet, int x = 0, int y = 0);
    ~GameObject();

    void Update();
    void Render();

private:
    int xPos, yPos;

    SDL_Texture* texture;
    SDL_Rect srcRect, destRect;
};

#endif //INC_2DGAMEENGINE_GAMEOBJECT_H
