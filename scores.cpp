#include "scores.h"
#include <iostream>

scores::scores(int p1win, int p2win, int tie)
{
p1win =0;
p2win =0;
tie =0;
}
void scores::addwin(int playid)
{
    if (playid ==1)
    {
        p1win++;
    }
    else
    p2wins++;
}
void scores::adddraw()
{
    tie++;
}
int scores::getp1win() const
{
    retuen p1win;
}
int scores::getp2win() const
{
    return p2win;
}
int scores::gettie() const
{
    return tie;
}

void scores:: printscore() Constructor
{
cout << "Number of wins for player 1: " << p1win << endl;
cout << "Number of wins for player 2: " << p2win << endl;
cout << " NUmber of ties: " << tie << endl;
}