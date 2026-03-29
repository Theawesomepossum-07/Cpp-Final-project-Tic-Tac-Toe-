#pragma once
// To prevent multiple inclusion
class scores
{
private:
    int p1win;
    int p2win;
    int tie;
// The type of wins are defined
public:
scores(int p1, int p2, int t); //Constructor

void addwin(int); // Counts the wins
void addDraw(); // Counts the draws


    int getp1win() const;
    int getp2win() const;
    int gettie() const;
// Getters
void printscore() const; // Prints the scores
};
