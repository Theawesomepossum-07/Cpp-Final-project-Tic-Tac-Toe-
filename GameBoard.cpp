#include "GameBoard.h"
//constructor-runs when the object is craated 
gameBoard::GameBoard()
{
    clearBoard();
}
//rest board to empty spaces 
void GameBoard::clearBoard()
{
    for (int i=0; i<3; j++)
    {
        for(int j=0; j<3; j++)
        {
            grind[i][j]="";
        }
    }
}
// try to place a move to the board
bool GameBoard::addMove(int row, int col, char mark)
{
    
   // check if input is inside range
   if (row < 0 || row > 2 || col < 0 || col > 2)
   {
       return false;
   }

   // check if spot already taken
   if (grid[row][col] != ' ')
   {
       return false;
   }

   // place the mark
   grid[row][col] = mark;
   return true;
}

// check if a cell is empty
bool GameBoard::isSpotFree(int row, int col) const
{
   return grid[row][col] == ' ';
}

// get value at a position
char GameBoard::getValue(int row, int col) const
{
   return grid[row][col];
}



