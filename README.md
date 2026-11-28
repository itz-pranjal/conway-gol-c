# Conway's Game of Life 

A simple implimentation of **Conway's game of life** build in C using [raylib].

"conway's game of life" or simple Life,is a cellural automaton devised by the british mathematician John Horton Conway in 1970.Despite having a few simple rules,it can produce fascinating patterns.

## ScreenShort 📸 

<p align="center">
<img src="./screen.png"width="500">
</p>

## Features
- Real-time automation simulation.
- lightweight implementation written in c.
- Simple keyboard controls.
- Restart functionality.

## How Does It Works?

The Game of Life consists of a grid of cells, where each cell can be in one of two states:

- Alive: The cell is active.
- Dead: The cell is inactive.

Each cell interacts with its eight neighboring cells (horizontally, vertically, and diagonally).

The status of every cell changes simultaneously with each generation according to four basic rules:

|Cell State |Live neighbors |Nest State                  |
|-----------|---------------|----------------------------|
|   Alive   |       0-1     |   Dies(Underpopulation)    |
|   Alive   |       2-3     |   Survives                 |
|   Alive   |       4-8     |   Dies(Overpopulation)     |
|   Dead    |    Ecactly 3  |   Become Alive(reproduce)  |

These simple rules create complex and sometimes unpredictable patterns.

## Controls 🎮 
|     Key    |           Action       |
|------------|------------------------|
| **Space**  |  To change mode.       |
|**R**       | Restart the simulation.|

## Installation 🛠️ 

### Building from source 

This project uses raylib for rendering graphics and handling windows management.

To build this project, you need a C compiler and [raylib](https://www.raylib.com/) installed on your system.
- Clone the repository 
```
git clone https://github.com/itz-pranjal/conway-gol-c
```

- Navigate to the project directory

```
cd conway-gol-c 

```

- Compile the source code 
```
gcc main.c -o gol -lraylib -O3 
```

- Run and enjoy
```
./gol
```

## Compilation Flags

Here's a brief explanation of the compiler flags used:

|   Flag    |   Description                          |
|-----------|----------------------------------------|
|   main.c  |   source file                          |
|   -o gol  |   Specifics the output executable name |
|   -lraylib|   Link the raylib lraylib              |
|   -O3     |   Enables compiler optimization        |

## limitations 

- **fixed grid size**: The simulation used a predefined grid siz
- **No Save/load**: simulation states cannot currently be saved or restored.

