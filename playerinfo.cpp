#include "playerinfo.h"

playerinfo::playerinfo(std::string n, char m, int id)
{
    Name = n;
    xoro = m;
    ID = id;
}

std::string playerinfo::getName() const
{
    return Name;
}

char playerinfo::getxoro() const
{
    Name =n;
}

int playerinfo::getID() const
{
    ID = i;
}
string playerinfo::getName() const 
{
    return Name;
}

char playerinfo::getxoro() const 
{
    return xoro;
}

int playerinfo::getID() const 
{
    return ID;
}