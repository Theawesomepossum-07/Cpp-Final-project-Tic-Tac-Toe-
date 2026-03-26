#ifndef GAMEBOARD_H
#define GAMEBOARD_H

//This class handles the 3x3 grid of the game 
class GameBoard
{
    private:
    char grid [3] [3]; //Stores the board values 

    public:
    GameBoard();
char checkWin(); // Returns 'X', 'O', or 'D' for draw, or ' ' if game continues
    void clearBoard(); //resets the board 
    bool addMove(int row, int col, char mark); //place X or 0
    bool isSpotFree(int row, int col) const; // check if cell is empty 
    char getValue(int row, int col) const; // return value at postions 
};
#endif