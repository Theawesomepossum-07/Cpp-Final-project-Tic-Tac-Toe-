#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "GameBoard.h" // lets this class use GameBoard
#include "MoveValidator.h" // lets this class use MoveValidator

// This class controls the full game
class GameManager
{
private:
    GameBoard board; // object for the board
    MoveValidator checker; // object to check winner or draw

    char activePlayer; // stores whose turn it is, X or O
    bool finished;     // true if game is over
    char result;       // stores X, O, or D for draw

public:
    GameManager(); // constructor

    void reset(); // reset the game state
    void newGame(); // start a new game
    bool playTurn(int row, int col); // handles one move
    void changePlayer(); // changes turn from X to O or O to X

    char getCurrentPlayer() const; // returns current player
    bool isFinished() const; // returns if game is over
    char getResult() const; // returns result of game
    const GameBoard& getBoard() const; // gives access to board
};

#endif
