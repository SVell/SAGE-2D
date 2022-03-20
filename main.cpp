#include "Game.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

Game* game = nullptr;

int main(int argc, char* args[]) {

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    game = new Game();
    game->Init("SellBro Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);

    while(game->Running()){
        frameStart = SDL_GetTicks();

        game->HandleEvents();
        game->Update();
        game->Render();

        frameTime = SDL_GetTicks() - frameStart;

        if(frameDelay >= frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game->Clean();
    delete game;

    return 0;
}
