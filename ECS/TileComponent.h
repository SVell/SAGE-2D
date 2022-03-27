#ifndef INC_2DGAMEENGINE_TILECOMPONENT_H
#define INC_2DGAMEENGINE_TILECOMPONENT_H

#include "ECS.h"
#include "TransformComponent.h"
#include "SDL.h"

class TileComponent : public Component{
public:
    TransformComponent* transform;
    SpriteComponent* sprite;

    SDL_Rect tileRect;
    int tileId;
    const char* path;

    TileComponent() = default;

    TileComponent(int x, int y, int w, int h, int id){
        tileRect.x = x;
        tileRect.y = y;
        tileRect.w = w;
        tileRect.h = h;
        tileId = id;

        switch (tileId) {
            case 0:
                path = "../Assets/Water.png";
                break;
            case 1:
                path = "../Assets/Dirt.png";
                break;
            case 2:
                path = "../Assets/Grass.png";
                break;
            default:
                break;
        }
    }

    void Init() override{
        entity->AddComponent<TransformComponent>(tileRect.x, tileRect.y, tileRect.w, tileRect.h, 1);
        transform = &entity->GetComponent<TransformComponent>();

        entity->AddComponent<SpriteComponent>(path);
        sprite = &entity->GetComponent<SpriteComponent>();
    }
};

#endif //INC_2DGAMEENGINE_TILECOMPONENT_H
