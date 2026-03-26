#include "GameManager.h"

// constructor
GameManager::GameManager()
{
    newGame();
}

// start or reset game
void GameManager::newGame()
{
    board.clearBoard();
    activePlayer = 'X';
    finished = false;
    result = ' ';
}

// handle a player's move
bool GameManager::playTurn(int row, int col)
{
    if (finished)
        return false;

    // try placing move
    if (!board.addMove(row, col, activePlayer))
        return false;

    // check winner
    if (checker.hasWinner(board, activePlayer))
    {
        finished = true;
        result = activePlayer;
        return true;
    }

    // check draw
    if (checker.isDrawGame(board))
    {
        finished = true;
        result = 'D';
        return true;
    }

    // switch turn if game continues
    changePlayer();
    return true;
}

// switch between X and O
void GameManager::changePlayer()
{
    activePlayer = (activePlayer == 'X') ? 'O' : 'X';
}

// getters
char GameManager::getCurrentPlayer() const
{
    return activePlayer;
}

bool GameManager::isFinished() const
{
    return finished;
}

char GameManager::getResult() const
{
    return result;
}

const GameBoard& GameManager::getBoard() const
{
    return board;
}
void GameManager::reset() {
    board.clearBoard(); // This calls your GameBoard's clear function
    finished = false;   // Reset your win/loss flag
    result = ' ';       // Reset the result character
    // If you track whose turn it is here, reset that to Player 1 too!
}