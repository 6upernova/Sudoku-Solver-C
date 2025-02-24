# This is a Sudoku solver implemented in c using the backtracking algorithm
Used for practicing C and Vim 

## Usage

1. Clone the repository
2. Select or copy your incomplete sudoku to a txt file using the format from the [sudokus]('https://github.com/6upernova/Sudoku-Solver-C/tree/main/sudokus') 
3. Compile the sudoku.c with gcc : 
    ´´´sh
       gcc -Wall -o sudoku sudoku.c
    ´´´
4. Execute and pass as an argument your txt file previously created:
    ´´´sh
    ./sudoku sudokuG1.txt
    ´´    ´´´´
## Info About Implementation

The backtracking algorithm explores each and every posible path in order to find a valid solution, in the sudoku case we use recursion to make this happen,
we can understand better with a graph:

<img src="2025-02-24 20_03_15-Window.png">

In the sudoku case the algorithm tries for each unasigned cell every number from 1 to 9, if the number is valid we explore every posible solution from that **Decision Point**, if the sudoku does not complete it means that the backtracking has activated and its trying for other posible solution.
 
