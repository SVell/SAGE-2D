#include "Game.h"
#include "Map.h"
#include "ECS/Components.h"
#include "Collision.h"

Map* map;
Manager manager;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

std::vector<ColliderComponent*> Game::colliders;

auto& player(manager.AddEntity());
auto& wall(manager.AddEntity());

enum GroupLabels : std::size_t {
    MapGroup,
    PlayerGroup,
    EnemyGroup,
    ColliderGroup
};

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

    Map::LoadMap("../Assets/Map16x16.map", 16, 16);

    player.AddComponent<TransformComponent>(2);
    player.AddComponent<KeyboardController>();
    player.AddComponent<SpriteComponent>("../Assets/PlayerIdle.png", 2, 400);
    player.AddComponent<ColliderComponent>("Player");
    player.AddGroup(PlayerGroup);

    wall.AddComponent<TransformComponent>(300, 300, 300, 20, 1);
    wall.AddComponent<SpriteComponent>("../Assets/Dirt.png");
    wall.AddComponent<ColliderComponent>("Wall");
    wall.AddGroup(MapGroup);
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

    for(auto cc : colliders){
        if(Collision::AABB(player.GetComponent<ColliderComponent>(), *cc)){
            SDL_Log("Wall Hit");
        }
    }
}

auto& tiles(manager.GetGroup(MapGroup));
auto& players(manager.GetGroup(PlayerGroup));
auto& enemies(manager.GetGroup(EnemyGroup));


void Game::Render() {
    SDL_RenderClear(renderer);
    for(auto& t : tiles){
        t->Draw();
    }

    for(auto& p : players){
        p->Draw();
    }

    for(auto& e : enemies){
        e->Draw();
    }

    SDL_RenderPresent(renderer);
}

void Game::Clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    std::cout << "Game cleaned" << std::endl;
}

void Game::AddTile(int id, int x, int y) {
    auto& tile(manager.AddEntity());
    tile.AddComponent<TileComponent>(x, y, 32, 32, id);
    tile.AddGroup(MapGroup);
}
