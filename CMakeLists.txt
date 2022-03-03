cmake_minimum_required(VERSION 3.20)
project(2DGameEngine)

set(CMAKE_CXX_STANDARD 14)

set(SDL2_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../SDL2/include)
set(SDL2_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../SDL2/lib/x86)
set(SDL2_IMAGE_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/../SDL2_Image/include)
set(SDL2_IMAGE_LIB_DIR ${CMAKE_SOURCE_DIR}/../SDL2_Image/lib/x86)

include_directories(${SDL2_INCLUDE_DIR})
include_directories(${SDL2_IMAGE_INCLUDE_DIR})

link_directories(${SDL2_LIB_DIR})
link_directories(${SDL2_IMAGE_LIB_DIR})

add_executable(2DGameEngine main.cpp Game.cpp Game.h)

# Should add dll files to SysWOW64
target_link_libraries(${PROJECT_NAME} SDL2main SDL2 SDL2_image)

