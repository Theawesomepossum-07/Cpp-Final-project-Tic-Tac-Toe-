#include "playerinfo.h"

playerinfo::playerinfo(std::string n, char m, int id) {
    Name = n;
    xoro = m;
    ID = id;
}

void playerinfo::setName(std::string n) { Name = n; }
void playerinfo::setxoro(char m) { xoro = m; }
void playerinfo::setID(int i) { ID = i; }

std::string playerinfo::getName() const { return Name; }
char playerinfo::getxoro() const { return xoro; }
int playerinfo::getID() const { return ID; }