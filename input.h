#pragma once

class input
{
private:
    int size;

public:
    explicit input(int s = 100);
    int grid(int mx, int my) const;
};
