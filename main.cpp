/*
Description: This is the main program for the sudoku solver.
Created by: Remzell Maranan (https://github.com/rmzmrnn)
Date Started: 26/05/2024
Based on the algorithm pulled from this website: https://www.tutorialspoint.com/sudoku-solver-in-cplusplus
*/

#include <iostream>
#include <string>
#include "sudoku_functions.hpp"

int grid[N][N];

int main(){
    int value = 0;
    int hints = 10;

    generateRow(grid);
    solveSudoku(grid);

    cout << "Sudoku puzzle generated...\n";
    
    fillBlanks(grid);
    printSudoku(grid);

    string command;
    string want_hint;
    bool isSolved;

    while (command != "quit"){
        cout << "Enter command: ";
        cin >> command;

        if (command == "h"){
            getHint(grid, hints);
            printSudoku(grid);
        }else if (isNumber(command)){
            grid[int(command[1]) - 49][int(command[2]) - 49] = int(command[0] - 48);
            printSudoku(grid);
        }else if(command == "solve"){
            if(checkBlanks(grid)){
                continue;
            }else{
                isSolved = checkSudoku(grid);
                if(isSolved){
                    cout << "Sudoku is solved! Well done!\n";
                    return 0;
                }
            }
        }else{
            cout << "Please enter a command\n";
        }
    }

    cout << "Exiting program...";

}