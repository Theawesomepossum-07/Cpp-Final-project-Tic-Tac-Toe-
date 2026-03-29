#include "MoveValidator.h" // connects this file to MoveValidator class

// this checks if a player has won
bool MoveValidator::hasWinner(const GameBoard& board, char mark) const
{
    // check rows
    // if all 3 spots in one row match the same mark, player wins
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
    // if all 3 spots in one column match the same mark, player wins
    for (int j = 0; j < 3; j++)
    {
        if (board.getValue(0, j) == mark &&
            board.getValue(1, j) == mark &&
            board.getValue(2, j) == mark)
        {
            return true;
        }
    }

    // check main diagonal
    // from top left to bottom right
    if (board.getValue(0, 0) == mark &&
        board.getValue(1, 1) == mark &&
        board.getValue(2, 2) == mark)
    {
        return true;
    }

    // check second diagonal
    // from top right to bottom left
    if (board.getValue(0, 2) == mark &&
        board.getValue(1, 1) == mark &&
        board.getValue(2, 0) == mark)
    {
        return true;
    }

    // if no row, column, or diagonal matched, no winner yet
    return false;
}

// this checks if the board is full
bool MoveValidator::isDrawGame(const GameBoard& board) const
{
    // go through every cell in the board
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // if one empty cell is found, game is not a draw yet
            if (board.getValue(i, j) == ' ')
            {
                return false;
            }
        }
    }

    // if loop finishes with no empty spots, board is full
    return true;
}
