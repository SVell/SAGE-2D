#ifndef INC_2DGAMEENGINE_COLLIDERCOMPONENT_H
#define INC_2DGAMEENGINE_COLLIDERCOMPONENT_H

#include <string>
#include "SDL.h"
#include "Components.h"

class ColliderComponent : public Component {

public:
    SDL_Rect collider;
    std::string tag;

    TransformComponent* transform;

    ColliderComponent(){
        tag = "Default";
    }

    ColliderComponent(std::string tag){
        this->tag = tag;
    }

    void Init() override{
        if(!entity->HasComponent<TransformComponent>()){
            entity->AddComponent<TransformComponent>();
        }

        transform = &entity->GetComponent<TransformComponent>();

        Game::colliders.push_back(this);
    }

    void Update() override{
        collider.x = static_cast<int>(transform->position.x);
        collider.y = static_cast<int>(transform->position.y);
        collider.w = transform->width * transform->scale;
        collider.h = transform->height * transform->scale;
    }
};

#endif //INC_2DGAMEENGINE_COLLIDERCOMPONENT_H
