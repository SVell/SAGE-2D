#ifndef INC_2DGAMEENGINE_TILECOMPONENT_H
#define INC_2DGAMEENGINE_TILECOMPONENT_H

#include "ECS.h"
#include "TransformComponent.h"
#include "SDL.h"

class TileComponent : public Component{
public:

    SDL_Texture* texture;
    SDL_Rect srcRect, destRect;

    TileComponent() = default;



    TileComponent(int srcX, int srcY, int x, int y, const char* path) {
        texture = TextureManager::LoadTexture(path);

        srcRect.x = srcX;
        srcRect.y = srcY;
        srcRect.w = srcRect.h = 32;

        destRect.x = x;
        destRect.y = y;
        destRect.w = destRect.h = 32;
    }

    ~TileComponent(){
        SDL_DestroyTexture(texture);
    }

    void Draw() override{
        TextureManager::Draw(texture, srcRect, destRect, SDL_FLIP_NONE);
    }
};

#endif //INC_2DGAMEENGINE_TILECOMPONENT_H
