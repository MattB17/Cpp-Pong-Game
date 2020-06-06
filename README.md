# CPP: Capstone Pong Game Project

This is a repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213).

The Capstone project is meant to illustrate the concepts of object-oriented programming, memory management, and concurrency in the `C++` programming language.

In fulfillment of this requirement, this repo implements a pong game. The initial idea for this game was taken from [this post](https://austinmorlan.com/posts/pong_clone/) but follows the layout given in [Udacity's Snake Game](https://github.com/udacity/CppND-Capstone-Snake-Game)

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
* DejaVu-TTF >= 2.37
  * All installation instructions can be found [here](https://sourceforge.net/projects/dejavu/files/dejavu/2.37/)
  * Note that for Linux an `apt` or `apt-get` installation is preferred to building from source:
    * `sudo apt-get -y install fonts-dejavu and fonts-dejavu-core`
  * Install the ttf file in a `fonts` folder in the root project directory
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./PongGame`.