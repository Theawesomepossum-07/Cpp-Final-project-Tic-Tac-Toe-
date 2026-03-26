#pragma once
using namespace std;

class scores
{
private:
    int p1win;
    int p2win;
    int tie;
public:
scores(int p1, int p2, int t);

void addwin(int);
void addDraw();
void adddraw();

int getp1win() const;
int getp2win() const;
int gettie() const;

void printscore() const;
};