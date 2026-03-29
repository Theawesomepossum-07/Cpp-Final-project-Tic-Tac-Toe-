#include "scores.h"
// Includes the header file
#include <iostream> // For displaying scores

scores::scores(int p1, int p2, int t)
{
    p1win = p1;
    p2win = p2;
    tie = t;
} // Intializes the values
void scores::addwin(int playid)
{
    if (playid == 1)
    {
        p1win++;
    }
    else
    p2win++;
} // Adds the win to player 1 and player 2

void scores::addDraw()
{
    tie++;
} // Counts the number of draws

int scores::getp1win() const
{
    return p1win;
}
int scores::getp2win() const
{
    return p2win;
}
int scores::gettie() const
{
    return tie;
}
// Returns the wins and draws
void scores:: printscore() const 
{
    std::cout << "Number of wins for player 1: " << p1win << std::endl;
    std::cout << "Number of wins for player 2: " << p2win << std::endl;
    std::cout << "Number of ties: " << tie << std::endl;
} // Displayes all the scores
