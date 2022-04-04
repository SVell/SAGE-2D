#ifndef INC_2DGAMEENGINE_COLLISION_H
#define INC_2DGAMEENGINE_COLLISION_H

#include "SDL.h"

class ColliderComponent;

class Collision {

public:
    static bool AABB(const SDL_Rect& recA, const SDL_Rect& recB);
    static bool AABB(const ColliderComponent& recA, const ColliderComponent& recB);
};


#endif //INC_2DGAMEENGINE_COLLISION_H
