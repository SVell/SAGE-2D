#ifndef INC_2DGAMEENGINE_TRANSFORMCOMPONENT_H
#define INC_2DGAMEENGINE_TRANSFORMCOMPONENT_H

#include "Components.h"
#include "../Vector2.h"

class TransformComponent : public Component {
public:
    Vector2 position;
    Vector2 velocity;

    int speed = 3;

    TransformComponent(){
        position.x = 0.0f;
        position.y = 0.0f;
    }

    TransformComponent(float x, float y){
        position.x = x;
        position.y = y;
    }

    void Init() override{
        velocity.x = 0;
        velocity.y = 0;
    }

    void Update() override{
        position.x += velocity.x * speed;
        position.y += velocity.y * speed;
    }
};

#endif //INC_2DGAMEENGINE_TRANSFORMCOMPONENT_H
