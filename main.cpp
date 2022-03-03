#include "Game.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

Game* game = nullptr;

int main(int argc, char* args[]) {
    game = new Game();

    game->Init("SellBro Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);

    while(game->Running()){
        game->HandleEvents();
        game->Update();
        game->Render();
    }

    game->Clean();
    delete game;

    return 0;
}
