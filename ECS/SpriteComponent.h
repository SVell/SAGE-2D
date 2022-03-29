#ifndef INC_2DGAMEENGINE_SPRITECOMPONENT_H
#define INC_2DGAMEENGINE_SPRITECOMPONENT_H

#include "../TextureManager.h"
#include "Animation.h"
#include <map>

class SpriteComponent : public Component {
private:
    TransformComponent* transform;
    SDL_Texture* texture;
    SDL_Rect srcRect, destRect;

    bool animated = false;
    int frames = 0;
    int speed = 100;

public:
    int animIndex = 0;

    std::map<const char*, Animation> animations;

    SDL_RendererFlip flipX = SDL_FLIP_NONE;

    SpriteComponent() = default;
    SpriteComponent(const char* texturePath){
        SetTexture(texturePath);
    }

    SpriteComponent(const char* texturePath, bool isAnimated) : animated(isAnimated) {

        Animation idle = Animation(2, 2, 400);
        Animation walk = Animation(1, 5, 200);

        animations.emplace("Idle", idle);
        animations.emplace("Walk", walk);

        Play("Idle");

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

        if(animated){
            srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
        }

        srcRect.y = animIndex * transform->height;

        destRect.x = static_cast<int>(transform->position.x);
        destRect.y = static_cast<int>(transform->position.y);
        destRect.w = transform->width * transform->scale;
        destRect.h = transform->height * transform->scale;
    }

    void Draw() override{
        TextureManager::Draw(texture, srcRect, destRect, flipX);
    }

    void Play(const char* animName){
        frames = animations[animName].frames;
        animIndex = animations[animName].index;
        speed = animations[animName].speed;
    }
};

#endif //INC_2DGAMEENGINE_SPRITECOMPONENT_H
