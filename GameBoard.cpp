#include "GameBoard.h"
//constructor-runs when the object is craated 
GameBoard::GameBoard()
{
    clearBoard();
}
//rest board to empty spaces 
void GameBoard::clearBoard()
{
    for (int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            grid[i][j]=' ';
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

char GameBoard::checkWin()
{
    // 1. Check Rows
    for (int i = 0; i < 3; i++) {
        if (grid[i][0] != ' ' && grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2])
            return grid[i][0];
    }

    // 2. Check Columns
    for (int j = 0; j < 3; j++) {
        if (grid[0][j] != ' ' && grid[0][j] == grid[1][j] && grid[1][j] == grid[2][j])
            return grid[0][j];
    }

    // 3. Check Diagonals
    if (grid[0][0] != ' ' && grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2])
        return grid[0][0];
    if (grid[0][2] != ' ' && grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0])
        return grid[0][2];

    // 4. Check for Draw (Board full but no winner)
    bool full = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] == ' ') full = false;
        }
    }
    if (full) return 'D'; // 'D' for Draw

    return ' '; // Game still going
}


