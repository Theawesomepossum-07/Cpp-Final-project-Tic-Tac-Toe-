#ifndef MOVEVALIDATOR_H
#define MOVEVALIDATOR_H

#include "GameBoard.h"

// This class checks game rules (win or draw)
class MoveValidator
{
public:
    bool hasWinner(const GameBoard& board, char mark) const;
    bool isDrawGame(const GameBoard& board) const;
};

#endif