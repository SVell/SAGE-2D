#ifndef INC_2DGAMEENGINE_GAME_H
#define INC_2DGAMEENGINE_GAME_H

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Game {

public:
    Game();
    ~Game();

    void Init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen);

    void HandleEvents();
    void Update();
    void Render();
    void Clean();

    bool Running(){return isRunning;}
private:
    bool isRunning;
    SDL_Window* window;
    SDL_Renderer* renderer;
};


#endif
