cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)

project(PongGame)
find_package(SDL2 REQUIRED)
find_package(SDL2TTF REQUIRED)
find_package(SDL2_mixer REQUIRED)
include_directories(
	${SDL2_INCLUDE_DIRS} 
    ${SDL2TTF_INCLUDE_DIR} 
    ${SDL2_MIXER_INCLUDE_DIRS} 
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/control
    ${CMAKE_SOURCE_DIR}/include/game
    ${CMAKE_SOURCE_DIR}/include/render)

add_executable(
	PongGame 
    
    src/main.cpp
    src/vec2d.cpp
    
    src/control/controller.cpp
    
    src/game/game.cpp
    src/game/ball.cpp 
    src/game/paddle.cpp 
    src/game/player.cpp
    
    src/render/renderer.cpp
    src/render/SDL_runner.cpp
    src/render/text_handler.cpp
    src/render/audio_handler.cpp)

string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
target_link_libraries(
	PongGame 
    ${SDL2_LIBRARIES} 
    ${SDL2TTF_LIBRARY} 
    ${SDL2_MIXER_LIBRARIES})
