#pragma once
using namespace std;

class scores
{
private:
    int p1win;
    int p2win;
    int tie;
public:
scores();

void addwin(int);
void addDraw();

int getp1win() const;
int getp2win() const;
int gettie() const;

void printscore() const;
}