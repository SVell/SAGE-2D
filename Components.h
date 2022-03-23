#ifndef INC_2DGAMEENGINE_COMPONENTS_H
#define INC_2DGAMEENGINE_COMPONENTS_H

#include "ECS.h"

class PositionComponent : public Component {
private:
    int xPos;
    int yPos;

public:
    int X() { return xPos; }
    int Y() { return yPos; }

    void Init() override{
        xPos = 0;
        yPos = 0;
    }

    void Update() override{
        xPos++;
        yPos++;
    }

    void SetPos(int x, int y){
        xPos = x;
        yPos = y;
    }

};

#endif //INC_2DGAMEENGINE_COMPONENTS_H
