#ifndef INC_2DGAMEENGINE_TRANSFORMCOMPONENT_H
#define INC_2DGAMEENGINE_TRANSFORMCOMPONENT_H

#include "Components.h"
#include "../Vector2.h"

class TransformComponent : public Component {
public:
    Vector2 position;

    TransformComponent(){
        position.x = 0.0f;
        position.y = 0.0f;
    }

    TransformComponent(float x, float y){
        position.x = x;
        position.y = y;
    }

    void Update() override{

    }
};

#endif //INC_2DGAMEENGINE_TRANSFORMCOMPONENT_H
