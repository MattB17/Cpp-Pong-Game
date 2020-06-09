cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)

project(PongGame)
find_package(SDL2 REQUIRED)
find_package(SDL2TTF REQUIRED)
find_package(SDL2_mixer REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2TTF_INCLUDE_DIR} ${SDL2_MIXER_INCLUDE_DIRS} src)

add_executable(PongGame src/main.cpp src/game.cpp src/controller.cpp src/renderer.cpp src/vec2d.cpp src/ball.cpp src/paddle.cpp src/player.cpp)
string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
target_link_libraries(PongGame ${SDL2_LIBRARIES} ${SDL2TTF_LIBRARY} ${SDL2_MIXER_LIBRARIES})
