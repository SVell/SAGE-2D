#ifndef INC_2DGAMEENGINE_TRANSFORMCOMPONENT_H
#define INC_2DGAMEENGINE_TRANSFORMCOMPONENT_H

#include "Components.h"
#include "../Vector2.h"

class TransformComponent : public Component {
public:
    Vector2 position;
    Vector2 velocity;

    int height = 32;
    int width = 32;
    int scale = 1;

    int speed = 3;

    TransformComponent(){
        position.x = 0.0f;
        position.y = 0.0f;
    }

    TransformComponent(int scale){
        position.x = 0.0f;
        position.y = 0.0f;

        this->scale = scale;
    }

    TransformComponent(float x, float y){
        position.x = x;
        position.y = y;
    }

    TransformComponent(float x, float y, int h, int w, int scale){
        position.x = x;
        position.y = y;
        height = h;
        width = w;
        this->scale = scale;
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
