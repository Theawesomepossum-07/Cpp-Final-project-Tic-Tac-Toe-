#include "input.h"

input::input(int s) : size(s) {}

int input::grid(int mx, int my) 
{
    int column = mx / size;
int row = my / size;

    if (column < 0 || column > 2 || row < 0 || row > 2)
    {
        return -1;
    }

    return row * 3 + column;
}
