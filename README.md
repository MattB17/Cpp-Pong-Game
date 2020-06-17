# CPP: Capstone Pong Game Project

![Pong Board](https://raw.github.com/MattB17/Cpp-Pong-Game/master/images/pong_game.png)

This is a repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213).

The Capstone project is meant to illustrate the concepts of object-oriented programming, memory management, and concurrency in the `C++` programming language.

In fulfillment of this requirement, this repo implements a pong game. The initial idea for this game was taken from [this post](https://austinmorlan.com/posts/pong_clone/) but follows the layout given in [Udacity's Snake Game](https://github.com/udacity/CppND-Capstone-Snake-Game). Additional features, including an AI component were inspired by the following [post](https://www.gamefromscratch.com/page/Game-From-Scratch-CPP-Edition.aspx)

This is a single version player of pong. The user controls the paddle on the left side of
the screen with the up and down errors. The paddle on the right is controlled by the computer.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* SDL2_ttf >= 2.0
  * All installation instructions can be found [here](https://www.libsdl.org/projects/SDL_ttf/)
  * Note that for Linux an `apt` or `apt-get` installation is preferred to building from source:
    * `sudo apt-get -y install libsdl2-ttf-dev`
  * For this to work a `FindSDL2TTF.cmake` file is required. This project has such a file in the `cmake` folder which was taken from the following [GitHub Page](https://github.com/Deraen/ohj2710/blob/master/cmake_modules/FindSDL2TTF.cmake)
* DejaVu-TTF >= 2.37
  * All installation instructions can be found [here](https://sourceforge.net/projects/dejavu/files/dejavu/2.37/)
  * Note that for Linux an `apt` or `apt-get` installation is preferred to building from source:
    * `sudo apt-get -y install fonts-dejavu and fonts-dejavu-core`
  * Install the ttf file in a `fonts` folder in the root project directory
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* SDL2_mixer >= 2.0
  * All installation instructions can be found on the [SDL2_Mixer Page](https://www.libsdl.org/projects/SDL_mixer/)
  * Note that for Linux an `apt` or `apt-get` installation is preferred to building from source:
    * `sudo apt-get -y install libsdl2-mixer-dev`
  * For this to work a `FindSDL2_mixer.cmake` file is required. This project has such a file in the `cmake` folder which was taken from this [GitHub Page](https://github.com/Tangent128/luasdl2/blob/master/cmake/FindSDL2_mixer.cmake)
  * In addition, two `.wav` files are required to render sound:
    * [PaddleHit.wav](https://freesound.org/people/NoiseCollector/sounds/4360/)
    * [WallHit.wav](https://freesound.org/people/NoiseCollector/sounds/4359/)
  * Download these two files and rename them as above. Place them in a `sounds` folder below the root project directory.

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./PongGame`.

# Code Overview
The code is organized into two directories: `src` and `include`. `include` contains all header files while `src` contains the implementations. In addition a `cmake` directory contains the `.cmake` files needed to compile the project.

The code implements a simple pong game using the HandleInput -> Update -> Render game loop. The classes are logically
organized into subdirectories corresponding to game control, update, and rendering.

# Rubric Adherence
The rubric is organized into 4 sections in which the project should cover at least 3 of the points across the sections.

The following explains how the project compares to the rubric across the 4 sections:

### Loops, Functions, I\O
* This game uses both while and for loops to control game flow. Such examples can be seen in the constructor and `Run` method of the Game class
* The game also accepts user input through the SDL library and uses this to update the player's paddle position. This can be seen in the `HandleInput` method of the controller class

### Object Oriented Programming
* The game is organized into a series of classes to handle input, update the game objects, and render them to the screen
* All data members are private (except when used for inheritance) and appropriate getter and setter methods are made public
* Inheritance is used within the project. The `GameObject` class is a base class used to represent a generic GameObject. `Ball` and `Paddle` inherit from this object.
* Composition is used throughout the project. Most of the classes in `include/game` are composed of `Vec2D` objects. The player class also contains a `Paddle` object. In addition, the `Renderer` class is composed of a `TextHandler` and
`AudioHandler`
* For many classes, multiple constructors are specified

### Memory Management
* Many of the methods in the `Renderer` class accept const references to objects from the game class. This is because the renderer is only responsible for displaying the objects and does not need to modify them
* Destructors are used explicitly in the `AudioHandler`, `TextHandler` and `Renderer` classes to deallocate resources
* The Rule of Five is used for all classes. Many classes do not allow copying or moving. However, the `GameObject`, `Paddle`, `Ball`, and `Player` classes do.
* The project uses move semantics throughout the `Game` and `Renderer` classes as well as the classes allowing copying or moving
* Both the `Game` class and `Renderer` class have `unique_ptr`s to the classes from which they are composed. The `Controller`, `Renderer`, `AudioHandler` and `TextHandler` classes also have a `shared_ptr` to an `SDL_Runner` class to ensure `SDL` is only initialized once and is destructed only when all `SDL` classes have been destroyed.
* The only raw pointers are used for SDL objects as SDL expects certain raw pointers.

### Concurrency
* The project uses multithreading in both the `Game` and `Renderer` classes.
  * The `Game` class uses multithreading at initialization to instantiate both players at the same time and also updates players concurrently
  * The `Renderer` uses multithreading to convert game objects to objects used for rendering simultaneously
* The project also uses `lock_guard` / `unique_lock`
  * A `lock_guard` is used in the `Game` class to lock the ball as both players need access to its position while it is being updated.
  * A `lock_guard` is also used in the `Renderer` class. Many objects used for rendering are created in parallel but the `SDL_Renderer` is only accessed under a lock