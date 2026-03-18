#include "playerinfo.h"


playerinfo::playerinfo(string n, char m, int id)
{
Name = n;
xoro = m;
ID = id;
}
void playerinfo::setName(string n)
{
    name =n;
}
void playerinfo::setxoro(char m) 
{ 
    xoro = m; 
}
void playerinfo::setID(int i) 
{
    id = i;
}
