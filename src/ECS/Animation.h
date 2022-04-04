#ifndef INC_2DGAMEENGINE_ANIMATION_H
#define INC_2DGAMEENGINE_ANIMATION_H

struct Animation{
    int index;
    int frames;
    int speed;

    Animation() = default;
    Animation(int i, int f, int s) : index(i), frames(f), speed(s){}
};

#endif //INC_2DGAMEENGINE_ANIMATION_H
