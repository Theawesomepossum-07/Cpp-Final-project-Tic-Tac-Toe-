#include "MoveValidator.h"

// check if a player has won
bool MoveValidator::hasWinner(const GameBoard& board, char mark) const
{
    // check rows
    for (int i = 0; i < 3; i++)
    {
        if (board.getValue(i, 0) == mark &&
            board.getValue(i, 1) == mark &&
            board.getValue(i, 2) == mark)
        {
            return true;
        }
    }

    // check columns
    for (int j = 0; j < 3; j++)
    {
        if (board.getValue(0, j) == mark &&
            board.getValue(1, j) == mark &&
            board.getValue(2, j) == mark)
        {
            return true;
        }
    }

    // check diagonals
    if (board.getValue(0, 0) == mark &&
        board.getValue(1, 1) == mark &&
        board.getValue(2, 2) == mark)
    {
        return true;
    }

    if (board.getValue(0, 2) == mark &&
        board.getValue(1, 1) == mark &&
        board.getValue(2, 0) == mark)
    {
        return true;
    }

    return false;
}

// check if board is full and no winner
bool MoveValidator::isDrawGame(const GameBoard& board) const
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board.getValue(i, j) == ' ')
            {
                return false; // still empty spots
            }
        }
    }

    return true; // no empty spots → draw
}