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
    return xoro;
}

int playerinfo::getID() const
{
    return ID;
}

void playerinfo::setName(std::string n)
{
    Name = n;
}

void playerinfo::setMarker(char m)
{
    xoro = m;
}

void playerinfo::setID(int i)
{
    ID = i;
}
