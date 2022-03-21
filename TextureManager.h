#ifndef INC_2DGAMEENGINE_TEXTUREMANAGER_H
#define INC_2DGAMEENGINE_TEXTUREMANAGER_H

#include "Game.h"
#include "SDL_image.h"

class TextureManager{
public:
    static SDL_Texture* LoadTexture(const char* fileName);
    static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
};

#endif //INC_2DGAMEENGINE_TEXTUREMANAGER_H
