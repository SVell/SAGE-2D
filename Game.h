#ifndef INC_2DGAMEENGINE_GAME_H
#define INC_2DGAMEENGINE_GAME_H

#include <iostream>
#include <SDL2/SDL.h>
#include <vector>

class ColliderComponent;

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

    static void AddTile(int srcX, int srcY, int x, int y);
    static SDL_Renderer* renderer;
    static SDL_Event event;

    static std::vector<ColliderComponent*> colliders;
private:
    bool isRunning;
    SDL_Window* window;
};


#endif
