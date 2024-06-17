/*
Description: This is the main program for the sudoku solver.
Created by: Remzell Maranan (https://github.com/rmzmrnn)
Date Started: 26/05/2024
*/

#include <iostream>
#include "sudoku_functions.hpp"

int grid[N][N] = {
    {3, 0, 6, 5, 0, 8, 4, 0, 0},
    {5, 2, 0, 0, 0, 0, 0, 0, 0},
    {0, 8, 7, 0, 0, 0, 0, 3, 1},
    {0, 0, 3, 0, 1, 0, 0, 8, 0},
    {9, 0, 0, 8, 6, 3, 0, 0, 5},
    {0, 5, 0, 0, 9, 0, 6, 0, 0},
    {1, 3, 0, 0, 0, 0, 2, 5, 0},
    {0, 0, 0, 0, 0, 0, 0, 7, 4},
    {0, 0, 5, 2, 0, 6, 3, 0, 0}
};

int main(){
   if (solveSudoku(grid) == true)
      sudokuGrid(grid);
   else
      cout << "No solution exists";
}