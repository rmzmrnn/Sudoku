/*
Description: This is the main program for the sudoku solver.
Created by: Remzell Maranan (https://github.com/rmzmrnn)
Date Started: 26/05/2024
*/

#include <iostream>
#include <string>
#include "sudoku_functions.hpp"

/*int grid[N][N] = {
    {3, 0, 6, 5, 0, 8, 4, 0, 0},
    {5, 2, 0, 0, 0, 0, 0, 0, 0},
    {0, 8, 7, 0, 0, 0, 0, 3, 1},
    {0, 0, 3, 0, 1, 0, 0, 8, 0},
    {9, 0, 0, 8, 6, 3, 0, 0, 5},
    {0, 5, 0, 0, 9, 0, 6, 0, 0},
    {1, 3, 0, 0, 0, 0, 2, 5, 0},
    {0, 0, 0, 0, 0, 0, 0, 7, 4},
    {0, 0, 5, 2, 0, 6, 3, 0, 0}
};*/

int grid[N][N];

int main(){
    int value = 0;
    for(int col = 0; col < N; col++){
        srand((unsigned) time(NULL));
        value = (rand() % 9) + 1;
        while(isPresentInRow(grid, 0, value)){
            value = (rand() % 9) + 1;
        }
        grid[0][col] = value;
    }

    //sudokuGrid(grid);
    //system("pause");

    string choice;

    if (solveSudoku(grid))
        cout << "Do you want to solve the puzzle? (yes/no): ";
        cin >> choice;
        if(choice == "yes"){
            fillBlanks(grid, BLANKS);
            sudokuGrid(grid);
        }else if(choice == "no")
            sudokuGrid(grid);
    else
        cout << "No solution exists";

}