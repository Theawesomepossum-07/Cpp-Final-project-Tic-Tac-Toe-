#ifndef MOVEVALIDATOR_H
#define MOVEVALIDATOR_H

#include "GameBoard.h" // needed because this class checks the board

// This class checks the rules of the game
class MoveValidator
{
public:
    bool hasWinner(const GameBoard& board, char mark) const;
    // checks if a player with mark X or O has won

    bool isDrawGame(const GameBoard& board) const;
    // checks if the board is full and game is a draw
};

#endif
