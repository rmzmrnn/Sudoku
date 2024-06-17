#include <iostream>
#define N 9
using namespace std;

bool isPresentInCol(int col, int num);
bool isPresentInRow(int row, int num);
bool isPresentInBox(int boxStartRow, int boxStartCol, int num)
void sudokuGrid();
bool findEmptyPlace(int &row, int &col);
bool isValidPlace(int row, int col, int num);
bool solveSudoku();