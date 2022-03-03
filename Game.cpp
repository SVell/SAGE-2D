#include "Game.h"

SDL_Texture* playerTex = nullptr;
SDL_Rect srcR, destR;

Game::Game() {

}

Game::~Game() {

}

void Game::Init(const char *title, int xPos, int yPos, int width, int height, bool fullscreen) {
    int flags = 0;

    if(fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_EVENTS) == 0){
        std:: cout << "Subsystems initialised!..." << std::endl;

        window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
        if(window != nullptr){
            std::cout << "Window created!" << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer != nullptr){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created!" << std::endl;
        }

        isRunning = true;
    }
    else{
        isRunning = false;
    }

    SDL_Surface* tempSurface = IMG_Load("../Assets/Player.png");
    playerTex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
}

void Game::HandleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
}

void Game::Update() {
    destR.h = 64;
    destR.w = 64;
}

void Game::Render() {
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, playerTex, NULL, &destR);

    SDL_RenderPresent(renderer);
}

void Game::Clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    std::cout << "Game cleaned" << std::endl;
}
