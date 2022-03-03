cmake_minimum_required(VERSION 3.20)
project(2DGameEngine)

set(CMAKE_CXX_STANDARD 14)

set(SDL2_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../SDL2/include)
set(SDL2_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../SDL2/lib/x86)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

add_executable(2DGameEngine main.cpp)

target_link_libraries(${PROJECT_NAME} SDL2main SDL2)
