#ifndef INC_2DGAMEENGINE_SPRITECOMPONENT_H
#define INC_2DGAMEENGINE_SPRITECOMPONENT_H

#include "../TextureManager.h"

class SpriteComponent : public Component {
private:
    TransformComponent* transform;
    SDL_Texture* texture;
    SDL_Rect srcRect, destRect;

public:
    SpriteComponent() = default;
    SpriteComponent(const char* texturePath){
        SetTexture(texturePath);
    }

    ~SpriteComponent(){
        SDL_DestroyTexture(texture);
    }

    void SetTexture(const char* path){
        texture = TextureManager::LoadTexture(path);
    }

    void Init() override{

        transform = &entity->GetComponent<TransformComponent>();

        srcRect.x = srcRect.y = 0;
        srcRect.w = transform->width;
        srcRect.h = transform->height;
    }

    void Update() override{
        destRect.x = static_cast<int>(transform->position.x);
        destRect.y = static_cast<int>(transform->position.y);
        destRect.w = transform->width * transform->scale;
        destRect.h = transform->height * transform->scale;
    }

    void Draw() override{
        TextureManager::Draw(texture, srcRect, destRect);
    }
};

#endif //INC_2DGAMEENGINE_SPRITECOMPONENT_H
