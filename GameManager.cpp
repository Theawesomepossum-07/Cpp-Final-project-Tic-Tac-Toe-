#include "GameManager.h" // connects this file to GameManager class

// constructor
// this runs when GameManager object is created
GameManager::GameManager()
{
    newGame(); // start with fresh game
}

// this starts or resets the game
void GameManager::newGame()
{
    board.clearBoard(); // make board empty
    activePlayer = 'X'; // X starts first
    finished = false; // game is not over
    result = ' '; // no result yet
}

// this handles one player's move
bool GameManager::playTurn(int row, int col)
{
    // if game already ended, do not allow more moves
    if (finished)
        return false;

    // try to place the move on the board
    // if move fails, return false
    if (!board.addMove(row, col, activePlayer))
        return false;

    // after placing move, check if current player won
    if (checker.hasWinner(board, activePlayer))
    {
        finished = true; // game ends
        result = activePlayer; // winner is current player
        return true;
    }

    // if no winner, check if game is a draw
    if (checker.isDrawGame(board))
    {
        finished = true; // game ends
        result = 'D'; // D means draw
        return true;
    }

    // if game is still going, switch to next player
    changePlayer();

    return true;
}

// this changes turn between X and O
void GameManager::changePlayer()
{
    // if current player is X, next is O
    // otherwise next is X
    activePlayer = (activePlayer == 'X') ? 'O' : 'X';
}

// getter for current player
char GameManager::getCurrentPlayer() const
{
    return activePlayer;
}

// getter to check if game is done
bool GameManager::isFinished() const
{
    return finished;
}

// getter to return winner or draw
char GameManager::getResult() const
{
    return result;
}

// getter to return board object
const GameBoard& GameManager::getBoard() const
{
    return board;
}

// this resets some game values
void GameManager::reset()
{
    board.clearBoard(); // clear board
    finished = false;   // game not over anymore
    result = ' ';       // clear old result
    // if needed, you can also put activePlayer = 'X'; here
}
