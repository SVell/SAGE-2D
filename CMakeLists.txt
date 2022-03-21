cmake_minimum_required(VERSION 3.20)
project(2DGameEngine)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR})

add_executable(2DGameEngine main.cpp Game.cpp Game.h TextureManager.h TextureManager.cpp GameObject.h GameObject.cpp Map.h Map.cpp)

# Should add dll files to SysWOW64
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} -lmingw32 -lSDL2main -lSDL2 -mwindows -lSDL2_image)

