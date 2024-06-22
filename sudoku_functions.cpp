#include "sudoku_functions.hpp"

struct Cell{
   int value;
   int row;
   int col;
};

Cell cell;
vector <Cell> cells;

int hint_grid[9][9];
int blanks = 40;

void generateRow(int (&grid)[9][9]){
   int value;
   for(int col = 0; col < N; col++){
        srand((unsigned) time(NULL));
        value = (rand() % 9) + 1;
        while(isPresentInRow(grid, 0, value)){
            value = (rand() % 9) + 1;
        }
        grid[0][col] = value;
    }
}

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

void printSudoku(int (&grid)[9][9]){
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

void fillBlanks(int (&grid)[9][9]){
   srand((unsigned) time(NULL));
   int row, col;

   for(blanks; blanks > 0; blanks--){
      row = rand() % 9;
      col = rand() % 9;

      while(hint_grid[row][col] != 0){
         row = rand() % 9;
         col = rand() % 9;
      }

      hint_grid[row][col] = grid[row][col];
      grid[row][col] = 0;
   }
}

int getHint(int (&grid)[9][9], int &hints){
   if(hints > 0){
      for(int row = 0; row < 9; row++){
         for(int col = 0; col < 9; col++){
            if(hint_grid[row][col] != 0){
               grid[row][col] = hint_grid[row][col];
               hint_grid[row][col] = 0;
               hints--;
               cout << "You have " << hints << "/10 hints left.\n";
               return 0;
            }
         }
      }
   }else{
      cout << "You have " << hints << ".\n";
   }
   return 0;
}

bool isNumber(string s){
   for(auto character:s){
      if(!isdigit(character)){
         return false;
      }
   }
   return true;
}

bool checkBlanks(int (&grid)[9][9]){
   for(int row = 0; row < 9; row++){
      for(int col = 0; col < 9; col++){
         if(grid[row][col] == 0){
            cout << "You still have blank/s in the puzzle.";
            return true;
         }
      }
   }
   return false;
}

bool checkSudoku(int (&grid)[9][9]){
   for(int row = 0; row < 9; row++){
      for(int col = 0; col < 9; col++){
         if(isValidPlace(grid, row, col, grid[row][col])){
            continue;
         }else{
            cell.value = grid[row][col];
            cell.row = row;
            cell.col = col;

            cells.push_back(cell);
         }
      }
   }

   if(!cells.empty()){
      for(auto cell:cells){
         cout << "Wrong Cells:\n";
         cout << "Value: " << cell.value << "\tRow: " << cell.row << "\tCol: " << cell.col << endl;
      }
      return false;
   }

   return true;

}