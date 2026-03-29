#include "GameBoard.h" // connects this file to the GameBoard class

// constructor
// this runs automatically when a GameBoard object is created
GameBoard::GameBoard()
{
    clearBoard(); // starts the board as empty
}

// this function clears the full board
// every position becomes an empty space
void GameBoard::clearBoard()
{
    // outer loop goes through rows
    for (int i = 0; i < 3; i++)
    {
        // inner loop goes through columns
        for (int j = 0; j < 3; j++)
        {
            grid[i][j] = ' '; // put empty space in each cell
        }
    }
}

// this function tries to place a move on the board
bool GameBoard::addMove(int row, int col, char mark)
{
    // this checks if the row or column is outside the board
    // if yes, the move is not valid
    if (row < 0 || row > 2 || col < 0 || col > 2)
    {
        return false; // invalid position
    }

    // this checks if the spot is already taken
    // if it is not empty, player cannot place there
    if (grid[row][col] != ' ')
    {
        return false; // spot already used
    }

    // if the spot is valid and empty, place the mark
    grid[row][col] = mark;

    return true; // move worked
}

// this checks if one cell is empty
bool GameBoard::isSpotFree(int row, int col) const
{
    // returns true if cell has empty space
    // returns false if cell has X or O
    return grid[row][col] == ' ';
}

// this returns the value at one location
char GameBoard::getValue(int row, int col) const
{
    // gives back what is in that cell
    return grid[row][col];
}

// this checks the board for win or draw
char GameBoard::checkWin()
{
    // 1. check all rows
    // if all 3 values in a row match and are not empty, someone won
    for (int i = 0; i < 3; i++) {
        if (grid[i][0] != ' ' && grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2])
            return grid[i][0]; // return X or O
    }

    // 2. check all columns
    // if all 3 values in a column match and are not empty, someone won
    for (int j = 0; j < 3; j++) {
        if (grid[0][j] != ' ' && grid[0][j] == grid[1][j] && grid[1][j] == grid[2][j])
            return grid[0][j]; // return X or O
    }

    // 3. check first diagonal
    // top left to bottom right
    if (grid[0][0] != ' ' && grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2])
        return grid[0][0];

    // 4. check second diagonal
    // top right to bottom left
    if (grid[0][2] != ' ' && grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0])
        return grid[0][2];

    // 5. check if board is full
    // if board is full and nobody won, then it is a draw
    bool full = true;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] == ' ')
                full = false; // found an empty space, so game is not draw yet
        }
    }

    // if full is still true, no empty spaces are left
    if (full)
        return 'D'; // D means draw

    // if no win and no draw, game still continues
    return ' ';
}
