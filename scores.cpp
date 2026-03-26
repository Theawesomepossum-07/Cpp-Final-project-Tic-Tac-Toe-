#include "scores.h"
#include <iostream>

scores::scores(int p1, int p2, int t)
{
    p1win = p1;
    p2win = p2;
    tie = t;
}
void scores::addwin(int playid)
{
    if (playid ==1)
    {
        p1win++;
    }
    else
    p2win++;
}
void scores::adddraw()
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

void scores:: printscore() const 
{
cout << "Number of wins for player 1: " << p1win << endl;
cout << "Number of wins for player 2: " << p2win << endl;
cout << " NUmber of ties: " << tie << endl;
}