#ifndef INC_2DGAMEENGINE_SPRITECOMPONENT_H
#define INC_2DGAMEENGINE_SPRITECOMPONENT_H

#include "../TextureManager.h"

class SpriteComponent : public Component {
private:
    PositionComponent* position;
    SDL_Texture* texture;
    SDL_Rect srcRect, destRect;

public:
    SpriteComponent() = default;
    SpriteComponent(const char* texturePath){
        SetTexture(texturePath);
    }

    void SetTexture(const char* path){
        texture = TextureManager::LoadTexture(path);
    }

    void Init() override{

        position = &entity->GetComponent<PositionComponent>();

        srcRect.x = srcRect.y = 0;
        srcRect.w = srcRect.h = 32;
        destRect.w = destRect.h = 64;
    }

    void Update() override{
        destRect.x = position->X();
        destRect.y = position->Y();
    }

    void Draw() override{
        TextureManager::Draw(texture, srcRect, destRect);
    }
};

#endif //INC_2DGAMEENGINE_SPRITECOMPONENT_H
