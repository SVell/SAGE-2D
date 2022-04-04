#ifndef INC_2DGAMEENGINE_MAP_H
#define INC_2DGAMEENGINE_MAP_H

#include <string>

class Map{
public:
   Map();
   ~Map();

   static void LoadMap(std::string path, int sizeX, int sizeY);

private:

};

#endif //INC_2DGAMEENGINE_MAP_H
