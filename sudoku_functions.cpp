#include "sudoku_functions.hpp"
#include <cstdlib>

const int ROWS = 9;
const int COLUMNS = 9;

bool createSudoku(int (&sudoku_arr)[9][9]){
    srand((unsigned) time(NULL));
    int value;
    int box[3][3];
    for(int row = 0; row < ROWS; row++){
        for(int col = 0; col < COLUMNS; col++){
            //if (sudoku_arr[row][col] == 0){
            value = (rand() % 9) + 1;
            // Check the row if the value already exists
            if (std::find(std::begin(sudoku_arr[row]), std::end(sudoku_arr[row]), value) == std::end(sudoku_arr[row])){
                // Check the column if the value already exists
                for(int i = 0; i < 9; i++){
                    if (sudoku_arr[i][col] != value && i < 8){
                        continue;
                    }else if (sudoku_arr[i][col] != value && i == 8){
                        // Setup the box
                        if (row < 3){
                            if (col < 3){
                                for(int i = 0; i < 3; i++){
                                    for(int j = 0; j < 3; j++){
                                        box[i][j] = sudoku_arr[i][j];
                                    }
                                }
                            }else if(col < 6){
                                for(int i = 0; i < 3; i++){
                                    for(int j = 0; j < 3; j++){
                                        box[i][j] = sudoku_arr[i + 3][j + 3];
                                    }
                                }
                            }else{
                                for(int i = 0; i < 3; i++){
                                    for(int j = 0; j < 3; j++){
                                        box[i][j] = sudoku_arr[i + 6][j + 6];
                                    }
                                }
                            }
                        }else if (row < 6){
                            if (col < 3){
                                for(int i = 3; i < 6; i++){
                                    for(int j = 0; j < 3; j++){
                                        box[i][j] = sudoku_arr[i][j];
                                    }
                                }
                            }else if(col < 6){
                                for(int i = 3; i < 6; i++){
                                    for(int j = 0; j < 3; j++){
                                        box[i][j] = sudoku_arr[i + 3][j + 3];
                                    }
                                }
                            }else{
                                for(int i = 3; i < 6; i++){
                                    for(int j = 0; j < 3; j++){
                                        box[i][j] = sudoku_arr[i + 6][j + 6];
                                    }
                                }
                            }
                        }else {
                            if (col < 3){
                                for(int i = 6; i < 9; i++){
                                    for(int j = 0; j < 3; j++){
                                        box[i][j] = sudoku_arr[i][j];
                                    }
                                }
                            }else if(col < 6){
                                for(int i = 6; i < 9; i++){
                                    for(int j = 0; j < 3; j++){
                                        box[i][j] = sudoku_arr[i + 3][j + 3];
                                    }
                                }
                            }else{
                                for(int i = 6; i < 9; i++){
                                    for(int j = 0; j < 3; j++){
                                        box[i][j] = sudoku_arr[i + 6][j + 6];
                                    }
                                }
                            }
                        }
                        // Check the box if the value already exists
                        for (int i = 0; i < 3; i++){
                            if (std::find(std::begin(box[i]), std::end(box[i]), value) != std::end(box[i])){
                                break;
                            }else if (i == 2 && std::find(std::begin(box[i]), std::end(box[i]), value) == std::end(box[i])){
                                sudoku_arr[row][col] = value;
                                if (sudokuChecker(sudoku_arr)){
                                    std::cout << "Grid Complete and Checked!\n";
                                    return true;
                                }else{
                                    if (createSudoku(sudoku_arr)){
                                        return true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            //}
        }
    }
    return false;
}

bool sudokuChecker(int (&sudoku_arr)[9][9]){
    //This is a function for checking duplicates in every cell
    for (int row = 0; row < ROWS; row++){
        for (int col = 0; col < COLUMNS; col++){
            if (sudoku_arr[row][col] == 0){
                return false;
            }
        }
    }
    return true;
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