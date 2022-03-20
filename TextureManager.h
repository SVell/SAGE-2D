#ifndef INC_2DGAMEENGINE_TEXTUREMANAGER_H
#define INC_2DGAMEENGINE_TEXTUREMANAGER_H

#include <SDL_image.h>

class TextureManager{
public:
    static SDL_Texture* LoadTexture(const char* fileName, SDL_Renderer* renderer);
};

#endif //INC_2DGAMEENGINE_TEXTUREMANAGER_H
