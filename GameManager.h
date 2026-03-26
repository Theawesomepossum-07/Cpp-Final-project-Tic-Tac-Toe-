#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "GameBoard.h"
#include "MoveValidator.h"

// This class controls the whole game flow
class GameManager
{
private:
    GameBoard board;
    MoveValidator checker;

    char activePlayer; // X or O
    bool finished;     // game over flag
    char result;       // X, O, or D (draw)

public:
    GameManager();
void reset(); // reset the game state
    void newGame(); // start/reset game
    bool playTurn(int row, int col); // process a move
    void changePlayer(); // switch turns

    char getCurrentPlayer() const;
    bool isFinished() const;
    char getResult() const;
    const GameBoard& getBoard() const;
};

#endif