/*
Description: This is the main program for the sudoku solver.
Created by: Remzell Maranan (https://github.com/rmzmrnn)
Date Started: 26/05/2024
*/

#include <iostream>
#include "sudoku_functions.hpp"

int BLANKS = 40;
int sudoku_arr[9][9];

int main(){
    while(!createSudoku(sudoku_arr)){
        //std::cout << "Creating Sudoku...\n";
        printSudoku(sudoku_arr);
    };
    //sudokuCleaner(sudoku_arr);
    //printSudoku(sudoku_arr);
    system("pause");
    //solveSudoku();
    return 0;
}