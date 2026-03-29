#include "input.h"
// Includes the header file 
input::input(int s) : size(s) {} // Constructor

int input::grid(int mx, int my) 
{
    int column = mx / size;
int row = my / size;
// Determine the row and column of the click
    if (column < 0 || column > 2 || row < 0 || row > 2)
    {
        return -1;
    } // Incase, the click is outside 

    return row * 3 + column; // Converts the row and coloumnn into a single index
}
