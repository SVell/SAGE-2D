#ifndef INC_2DGAMEENGINE_KEYBOARDCONTROLLER_H
#define INC_2DGAMEENGINE_KEYBOARDCONTROLLER_H

#include "../Game.h"
#include "ECS.h"

class KeyboardController : public Component{

public:
    TransformComponent* transform;
    SpriteComponent* sprite;

    void Init() override{
        transform = &entity->GetComponent<TransformComponent>();
        sprite = &entity->GetComponent<SpriteComponent>();
    }

    void Update() override{
        if(Game::event.type == SDL_KEYDOWN){
            switch (Game::event.key.keysym.sym) {
                case SDLK_w:
                    transform->velocity.y = -1;
                    sprite->Play("Walk");
                    break;
                case SDLK_a:
                    transform->velocity.x = -1;
                    sprite->Play("Walk");
                    sprite->flipX = SDL_FLIP_HORIZONTAL;
                    break;
                case SDLK_s:
                    transform->velocity.y = 1;
                    sprite->Play("Walk");
                    break;
                case SDLK_d:
                    transform->velocity.x = 1;
                    sprite->Play("Walk");
                    sprite->flipX = SDL_FLIP_NONE;
                    break;
                default:
                    break;
            }
        }

        if(Game::event.type == SDL_KEYUP){
            switch (Game::event.key.keysym.sym) {
                case SDLK_w:
                    transform->velocity.y = 0;
                    sprite->Play("Idle");
                case SDLK_a:
                    transform->velocity.x = 0;
                    sprite->Play("Idle");
                    break;
                case SDLK_s:
                    transform->velocity.y = 0;
                    sprite->Play("Idle");
                    break;
                case SDLK_d:
                    transform->velocity.x = 0;
                    sprite->Play("Idle");
                    break;
                default:
                    break;
            }
        }
    }
};

#endif //INC_2DGAMEENGINE_KEYBOARDCONTROLLER_H
