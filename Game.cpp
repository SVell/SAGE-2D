#include "Game.h"
#include "Map.h"
#include "ECS/Components.h"
#include "Collision.h"

Map* map;
Manager manager;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

auto& player(manager.AddEntity());
auto& wall(manager.AddEntity());

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
        SDL_Log("Subsystems initialised!...");

        window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
        if(window != nullptr){
            SDL_Log("Window created!");
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer != nullptr){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_Log("Renderer created!");
        }

        isRunning = true;
    }
    else{
        isRunning = false;
    }

    map = new Map();

    player.AddComponent<TransformComponent>(2);
    player.AddComponent<KeyboardController>();
    player.AddComponent<SpriteComponent>("../Assets/Player.png");
    player.AddComponent<ColliderComponent>("Player");

    wall.AddComponent<TransformComponent>(300, 300, 300, 20, 1);
    wall.AddComponent<SpriteComponent>("../Assets/Dirt.png");
    wall.AddComponent<ColliderComponent>("Wall");
}

void Game::HandleEvents() {
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
    manager.Refresh();
    manager.Update();

    setbuf(stdout, NULL);

    if(Collision::AABB(player.GetComponent<ColliderComponent>().collider,
                       wall.GetComponent<ColliderComponent>().collider)){
        SDL_Log("Wall Hit");
    }
}

void Game::Render() {
    SDL_RenderClear(renderer);

    map->DrawMap();
    manager.Draw();

    SDL_RenderPresent(renderer);
}

void Game::Clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    std::cout << "Game cleaned" << std::endl;
}
