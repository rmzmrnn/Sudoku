#include "sudoku_functions.hpp"

bool isPresentInCol(int (&grid)[9][9], int col, int num){ //check whether num is present in col or not
   for (int row = 0; row < N; row++)
      if (grid[row][col] == num)
         return true;
   return false;
}

bool isPresentInRow(int (&grid)[9][9], int row, int num){ //check whether num is present in row or not
   for (int col = 0; col < N; col++)
      if (grid[row][col] == num)
         return true;
   return false;
}

bool isPresentInBox(int (&grid)[9][9], int boxStartRow, int boxStartCol, int num){
//check whether num is present in 3x3 box or not
   for (int row = 0; row < 3; row++)
      for (int col = 0; col < 3; col++)
         if (grid[row+boxStartRow][col+boxStartCol] == num)
            return true;
   return false;
}

void sudokuGrid(int (&grid)[9][9]){
    cout << "-------------------------------\n";
    for(int row = 0; row < N; row++){
        cout << "|";
        for(int col = 0; col < N; col++){
            cout << " " << grid[row][col] << " ";
            if((col + 1) % 3 == 0)
                cout << "|";
        }
        
        cout << "\n";

        if((row + 1) % 3 == 0)
            cout << "-------------------------------\n";
    }
}

bool findEmptyPlace(int (&grid)[9][9], int &row, int &col){ //get empty location and update row and column
   for (row = 0; row < N; row++)
      for (col = 0; col < N; col++)
         if (grid[row][col] == 0) //marked with 0 is empty
            return true;
   return false;
}

bool isValidPlace(int (&grid)[9][9], int row, int col, int num){
   //when item not found in col, row and current 3x3 box
   return !isPresentInRow(grid, row, num) && !isPresentInCol(grid, col, num) && !isPresentInBox(grid, row - row % 3, col - col % 3, num);
}

bool solveSudoku(int (&grid)[9][9]){
   int row, col;
   if (!findEmptyPlace(grid, row, col))
      return true; //when all places are filled
   for (int num = 1; num <= 9; num++){ //valid numbers are 1 - 9
      if (isValidPlace(grid, row, col, num)){ //check validation, if yes, put the number in the grid
         grid[row][col] = num;
         if (solveSudoku(grid)) //recursively go for other rooms in the grid
            return true;
         grid[row][col] = 0; //turn to unassigned space when conditions are not satisfied
      }
   }
   return false;
}