#include "input.h"

input::input(int s): cize(s) {}

int input::grid(int mx, int my)
{
    int column = mx / cize;
int row = my / cize;

    if (column||column >2||row <0 ||row >2)
    {
        return -1;
    }
    return row*3 +column;
}