#include <cstdlib>
#include <iostream>
#include <algorithm>

void createSudoku(int (&sudoku_arr)[9][9]);
//bool sudokuChecker(int (&sudoku_arr)[9][9]);
bool rowChecker(int value, int (&sudoku_arr)[9], int col);
bool colChecker(int value, int (&sudoku_arr)[9][9], int row, int col);
bool boxChecker(int value, int (&sudoku_arr)[9][9], int row, int col);
void printSudoku(int (&sudoku_arr)[9][9]);