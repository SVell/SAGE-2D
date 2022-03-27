#include "Collision.h"
#include "ECS/ColliderComponent.h"

bool Collision::AABB(const SDL_Rect &recA, const SDL_Rect &recB) {
    if(recA.x + recA.w >= recB.x &&
    recB.x + recB.w >= recA.x &&
    recA.y + recA.h >= recB.y &&
    recB.y + recB.h >= recA.y){
        return true;
    }

    return false;
}

bool Collision::AABB(const ColliderComponent &recA, const ColliderComponent &recB) {
    if(AABB(recA.collider, recB.collider)){
        return true;
    }

    return false;
}
