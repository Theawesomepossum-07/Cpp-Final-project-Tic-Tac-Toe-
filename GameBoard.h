#ifndef GAMEBOARD_H
#define GAMEBOARD_H

// This class handles the 3x3 board for Tic-Tac-Toe
class GameBoard
{
private:
    char grid[3][3]; // this stores the values in the board

public:
    GameBoard(); // constructor

    char checkWin(); 
    // checks if X won, O won, draw happened, or if game is still going
    // returns:
    // 'X' if X wins
    // 'O' if O wins
    // 'D' if it is a draw
    // ' ' if the game is still going

    void clearBoard(); // clears the full board back to empty spaces

    bool addMove(int row, int col, char mark); 
    // tries to place X or O in a spot
    // returns true if move works
    // returns false if move is not allowed

    bool isSpotFree(int row, int col) const; 
    // checks if a certain spot is empty or not

    char getValue(int row, int col) const; 
    // returns the value in one position of the board
};

#endif
