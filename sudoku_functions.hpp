#include <iostream>
#define N 9
using namespace std;

const int BLANKS = 40;

bool isPresentInCol(int (&grid)[9][9], int col, int num);
bool isPresentInRow(int (&grid)[9][9], int row, int num);
bool isPresentInBox(int (&grid)[9][9], int boxStartRow, int boxStartCol, int num);
void sudokuGrid(int (&grid)[9][9]);
bool findEmptyPlace(int (&grid)[9][9], int &row, int &col);
bool isValidPlace(int row, int col, int num);
bool solveSudoku(int (&grid)[9][9]);
void fillBlanks(int (&grid)[9][9], int blanks);