#ifndef INC_2DGAMEENGINE_POSITIONCOMPONENT_H
#define INC_2DGAMEENGINE_POSITIONCOMPONENT_H

class PositionComponent : public Component {
private:
    int xPos;
    int yPos;

public:
    PositionComponent(){
        xPos = 0;
        yPos = 0;
    }

    PositionComponent(int x, int y){
        xPos = x;
        yPos = y;
    }

    int X() { return xPos; }
    int Y() { return yPos; }

    void Update() override{
        xPos++;
        yPos++;
    }

    void SetPos(int x, int y){
        xPos = x;
        yPos = y;
    }

};

#endif //INC_2DGAMEENGINE_POSITIONCOMPONENT_H
