#include <iostream>
#include <vector>
#include <string.h>
#include <typeinfo>
#define N 9
using namespace std;

void generateRow(int (&grid)[9][9]);
bool isPresentInCol(int (&grid)[9][9], int col, int num);
bool isPresentInRow(int (&grid)[9][9], int row, int num);
bool isPresentInBox(int (&grid)[9][9], int boxStartRow, int boxStartCol, int num);
void printSudoku(int (&grid)[9][9]);
bool findEmptyPlace(int (&grid)[9][9], int &row, int &col);
bool isValidPlace(int row, int col, int num);
bool solveSudoku(int (&grid)[9][9]);
void fillBlanks(int (&grid)[9][9]);
int getHint(int (&grid)[9][9], int &hints);
bool isNumber(string s);
bool checkBlanks(int (&grid)[9][9]);
bool checkSudoku(int (&grid)[9][9]);