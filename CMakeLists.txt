cmake_minimum_required(VERSION 3.20)
project(2DGameEngine)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR})

add_executable(2DGameEngine src/main.cpp src/Game.cpp src/Game.h src/TextureManager.h src/TextureManager.cpp src/GameObject.h src/GameObject.cpp src/Map.h src/Map.cpp src/ECS/ECS.h src/ECS/Components.h src/ECS/SpriteComponent.h src/ECS/TransformComponent.h src/Vector2.cpp src/Vector2.h src/ECS/KeyboardController.h src/ECS/ColliderComponent.h src/Collision.cpp src/Collision.h src/ECS/TileComponent.h src/ECS/ECS.cpp src/ECS/Animation.h)

# Should add dll files to SysWOW64
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} -lmingw32 -lSDL2main -lSDL2 -mwindows -lSDL2_image)

