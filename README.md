# Conway's Game of Life

This is a simple implementation of Conway's Game of Life in C++ using SDL2.

## Prerequisites

* C++ compiler (clang++, with C++20 is used in this project)
* SDL2 (https://github.com/libsdl-org/SDL/releases) 

> Note: You can install SDL2 using Homebrew on macOS: `brew install sdl2`. Follow the instructions on the SDL2 website for other platforms.

## Build

`make.sh` script is provided to build the project. It will create a `build` directory and put the executable in it.

```bash
chmod +x make.sh   # Make the script executable, if needed
./make.sh          # Build the project
```

## Run

```bash
./build/gameOfLife
```
