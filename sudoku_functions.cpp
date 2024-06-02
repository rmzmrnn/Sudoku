#include "sudoku_functions.hpp"
#include <cstdlib>

void createSudoku(int (&sudoku_arr)[9][9]){
    srand((unsigned) time(NULL));
    for(int row = 0; row < ROWS; row++){
        for(int col = 0; col < COLUMNS; col++){
            sudoku_arr[row][col] = (rand() % 9) + 1;
        }
    }

    int rand_row;
    int rand_col;
    srand((unsigned) time(NULL));

    while(BLANKS > 0){
        rand_row = rand() % 10;
        rand_col = rand() % 10;

        if(sudoku_arr[rand_row][rand_col] == 0)
            continue;
        else{
            BLANKS--;
            sudoku_arr[rand_row][rand_col] = 0;
        }
    }
}

void sudokuChecker(int (&sudoku_arr)[9][9]){
    //This is a function for checking duplicates in every cell
    
}

void printSudoku(int (&sudoku_arr)[9][9]){
    std::cout << "-------------------------------\n";
    for(int row = 0; row < ROWS; row++){
        std::cout << "|";
        for(int col = 0; col < COLUMNS; col++){
            std::cout << " " << sudoku_arr[row][col] << " ";
            if((col + 1) % 3 == 0)
                std::cout << "|";
        }
        
        std::cout << "\n";

        if((row + 1) % 3 == 0)
            std::cout << "-------------------------------\n";
    }
}