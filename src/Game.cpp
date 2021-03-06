#include "Game.h"
#include "Map.h"
#include "ECS/Components.h"
#include "Collision.h"

Map* map;
Manager manager;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

std::vector<ColliderComponent*> Game::colliders;

bool Game::isRunning = false;

auto& player(manager.AddEntity());
auto& wall(manager.AddEntity());

const char* mapFile = "../Assets/terrain_ss.png";

enum GroupLabels : std::size_t {
    MapGroup,
    PlayerGroup,
    EnemyGroup,
    ColliderGroup
};

auto& tiles(manager.GetGroup(MapGroup));
auto& players(manager.GetGroup(PlayerGroup));
auto& enemies(manager.GetGroup(EnemyGroup));


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

    Map::LoadMap("../Assets/Map.map", 25, 20);

    player.AddComponent<TransformComponent>(1);
    player.AddComponent<SpriteComponent>("../Assets/PlayerAnims.png", true);
    player.AddComponent<KeyboardController>();
    player.AddComponent<ColliderComponent>("Player");
    player.AddGroup(PlayerGroup);
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

    Vector2 playerVelocity = player.GetComponent<TransformComponent>().velocity;
    int playerSpeed = player.GetComponent<TransformComponent>().speed;

    for(auto t : tiles){
        t->GetComponent<TileComponent>().destRect.x += -(playerVelocity.x * playerSpeed);
        t->GetComponent<TileComponent>().destRect.y += -(playerVelocity.y * playerSpeed);
    }
}

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

void Game::AddTile(int srcX, int srcY, int x, int y) {
    auto& tile(manager.AddEntity());
    tile.AddComponent<TileComponent>(srcX, srcY, x, y, mapFile);
    tile.AddGroup(MapGroup);
}
