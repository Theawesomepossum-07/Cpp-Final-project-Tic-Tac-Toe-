#include "scores.h"

#include <iostream>

scores::scores() : p1win(0), p2win(0), tie(0) {}

void scores::addwin(int playid)
{
    if (playid == 1)
    {
        p1win++;
    }
    else
    {
        p2win++;
    }
}

void scores::addDraw()
{
    tie++;
}

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

void scores::printscore() const
{
    std::cout << "Number of wins for player 1: " << p1win << std::endl;
    std::cout << "Number of wins for player 2: " << p2win << std::endl;
    std::cout << "Number of ties: " << tie << std::endl;
}
