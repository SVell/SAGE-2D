#ifndef INC_2DGAMEENGINE_COLLISION_H
#define INC_2DGAMEENGINE_COLLISION_H

#include "SDL.h"

class Collision {

public:
    static bool AABB(const SDL_Rect& recA, const SDL_Rect& recB);
};


#endif //INC_2DGAMEENGINE_COLLISION_H
