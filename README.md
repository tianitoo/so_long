# **so_long** - A Simple Game Project

## Overview

**so_long** is a project from the 42 Network curriculum that involves creating a simple 2D game using the MiniLibX graphics library. The goal is to implement a game where the player navigates through a map, collecting items and reaching a target while avoiding obstacles.

## Table of Contents

- [Overview](#overview)
- [Function Prototypes](#function-prototypes)
- [Project Structure](#project-structure)
- [How It Works](#how-it-works)
- [Compilation and Usage](#compilation-and-usage)

## Function Prototypes

```c
void initialize_game(void);
void render_map(void);
int handle_input(int key);
```

- **Parameters**:
  - `initialize_game`: Initializes the game window and variables.
  - `render_map`: Draws the game map on the window.
  - `handle_input`: Processes player input.

- **Return**:
  - Each function does not return a value; they manage the game state and rendering.

## Project Structure

```
so_long/
│
├── Makefile
├── so_long.h
├── src/
│   ├── main.c
│   ├── game.c
│   ├── graphics.c
│   └── ...
└── README.md
```

- **main.c**: The entry point of the game program.
- **game.c**: Contains the main game logic and state management.
- **graphics.c**: Functions for rendering the game graphics.
- **so_long.h**: The header file containing function prototypes and necessary definitions.
- **Makefile**: Used for compiling the project.

## How It Works

The **so_long** program operates as follows:
- It initializes the game window and loads the map.
- The player can navigate the map using keyboard inputs.
- The game continuously renders the updated state of the map and player position.
- The objective is to collect all items and reach the exit.

## Compilation and Usage

You can compile the project using the provided **Makefile**. To generate the object files and the final program, run the following commands:

```bash
# Compile the program
make

# Clean up object files
make clean

# Clean everything (object files and binary)
make fclean

# Recompile everything
make re
```

### Usage in Projects

To use **so_long**, compile it and run the executable:

```bash
./so_long map.ber
```

Replace `map.ber` with the path to your game map file.
