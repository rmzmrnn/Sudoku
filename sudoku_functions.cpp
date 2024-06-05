#include "sudoku_functions.hpp"
#include <cstdlib>

const int ROWS = 9;
const int COLUMNS = 9;

bool createSudoku(int (&sudoku_arr)[9][9]){
    int value;
    int row = 0;
    int col = 0;
    for(row; row < ROWS; row++){
        for(col; col < COLUMNS; col++){
            srand(time(NULL));
            value = (rand() % 9) + 1;
            while(!(rowChecker(value, sudoku_arr[row], col) && colChecker(value, sudoku_arr, row, col) && boxChecker(value, sudoku_arr, row, col))){
                
                if(!boxChecker(value, sudoku_arr, row, col)){
                    col--;
                    if(col < 0){
                        row--;
                        col = 8;
                    }
                    sudoku_arr[row][col] = 0;
                }
                
                value = (rand() % 9) + 1;
                printSudoku(sudoku_arr);
            }
            sudoku_arr[row][col] = value;
        }
    }
    return false;
}

/*bool sudokuChecker(int (&sudoku_arr)[9][9]){
    //This is a function for checking duplicates in every cell
    for (int row = 0; row < ROWS; row++){
        for (int col = 0; col < COLUMNS; col++){
            if (sudoku_arr[row][col] == 0){
                return false;
            }
        }
    }
    return true;
}*/

bool rowChecker(int value, int (&row_arr)[9], int col){
    for(int i = 0; i < 9; i++){
        if(i == col)
            continue;
        
        if(row_arr[i] == value)
            return false;
    }
    return true;
}

bool colChecker(int value, int (&sudoku_arr)[9][9], int row, int col){
    for(int i = 0; i < 9; i++){
        if(i == row)
            continue;
        
        if(sudoku_arr[i][col] == value)
            return false;
    }
    return true;
}

bool boxChecker(int value, int (&sudoku_arr)[9][9], int row, int col){
    int box[3][3];

    if (row < 3){
        if (col < 3){
            for(int i = 0; i < 3; i++)
                for(int j = 0; j < 3; j++){
                    if (i == row && j == col)
                        box[i][j] = 0;
                    box[i][j] = sudoku_arr[i][j];
                }
        }else if (col < 6){
            for(int i = 0; i < 3; i++)
                for(int j = 0; j < 3; j++){
                    if (i == row && j + 3 == col)
                        box[i][j] = 0;
                    box[i][j] = sudoku_arr[i][j + 3];
                }
        }else{
            for(int i = 0; i < 3; i++)
                for(int j = 0; j < 3; j++){
                    if (i == row && j + 6 == col)
                        box[i][j] = 0;
                    box[i][j] = sudoku_arr[i][j + 6];
                }
        }
    }else if (row < 6){
        if (col < 3){
            for(int i = 3; i < 6; i++)
                for(int j = 0; j < 3; j++){
                    if (i == row && j == col)
                        box[i - 3][j] = 0;
                    box[i - 3][j] = sudoku_arr[i][j];
                }
        }else if (col < 6){
            for(int i = 3; i < 6; i++)
                for(int j = 0; j < 3; j++){
                    if (i == row && j + 3 == col)
                        box[i - 3][j] = 0;
                    box[i - 3][j] = sudoku_arr[i][j + 3];
                }
        }else{
            for(int i = 3; i < 6; i++)
                for(int j = 0; j < 3; j++){
                    if (i == row && j + 6 == col)
                        box[i - 3][j] = 0;
                    box[i - 3][j] = sudoku_arr[i][j + 6];
                }
        }
    }else{
        if (col < 3){
            for(int i = 6; i < 9; i++)
                for(int j = 0; j < 3; j++){
                    if (i == row && j == col)
                        box[i - 6][j] = 0;
                    box[i - 6][j] = sudoku_arr[i][j];
                }
        }else if (col < 6){
            for(int i = 6; i < 9; i++)
                for(int j = 0; j < 3; j++){
                    if (i == row && j + 3 == col)
                        box[i - 6][j] = 0;
                    box[i - 6][j] = sudoku_arr[i][j + 3];
                }
        }else{
            for(int i = 6; i < 9; i++)
                for(int j = 0; j < 3; j++){
                    if (i == row && j + 6 == col)
                        box[i - 6][j] = 0;
                    box[i - 6][j] = sudoku_arr[i][j + 6];
                }
        }
    }

    for(int i = 0; i < 3; i++){
        if(std::find(std::begin(box[i]), std::end(box[i]), value) != std::end(box[i])){
            return false;
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