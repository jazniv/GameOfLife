# GameOfLife

## Introduction 💡 

Game of Life is a cellular automation devised by the British mathematician John Horton Conway in 1970. Its evolution is determined by its initial state, requiring no further input. One interacts with the Game of Life by creating an initial configuration and observing how it evolves. The aim of this project is to simulate the evolution of bacteria through user input of dimensions for their configuration. 

## How to Play 🌱

###### Input Dimensions 📏 

When the program begins, the user will be prompted to provide either a:

  1. Map file of the world
  2. Random assignment

For the mapped option, the .txt file should be formatted as follows:

  1. First line: Height of Grid (number of rows)
  2. Second line: Width of Grid (number of columns)
  3. Following lines represent the rows of the grid (X for occupied, - for empty)

###### Select your Mode 🦠

There are three modes supported by this program:

1. Classic Mode
   - All locations off the grid are considered to be empty.

2. Doughnut Mode
   - The grid is wrapped around itself horizontally and vertically, resulting in a doughnut shape. Any references on edges are wrapped around to the opposite side.

3. Mirror Mode
   - Reflections on the edges of the grid are bounced back to them, referencing additional neighbors.

###### Observe the Evolution! 🪴 

The program will output the evolution based on the user's selection: a brief pause between evolutions (standard out), pressing "enter" to advance each evolution (standard out), or outputting to a file.

Each evolution is determined by the average number of neighbors from the current and previous two generations.
- If the location has an average of less than 1.5 neighbors, it will be empty
- If the location has an average of 1.5 to 2.5 neighbors, it will remain stable (empty or filled)
- If the location has an average of 2.51 to 3.5 neighbors, if will contain a cell
- If the location has an average of above 3.51 neighbors, it will be empty

## Notes & Limitations 🖥

- Program is unable to create a 1x1 grid. User input will not allow for this
- Additional generation past the second generation is accounted for when checking oscillation to end program
- Program stops at 10,000 generations regardless of stability/emptiness status
