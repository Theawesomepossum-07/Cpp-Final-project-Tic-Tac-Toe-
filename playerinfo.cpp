#include "playerinfo.h"
// Includes the heard file
playerinfo::playerinfo(std::string n, char m, int id) {
    Name = n;
    xoro = m;
    ID = id;
} // Constructor

void playerinfo::setName(std::string n) { Name = n; }
void playerinfo::setxoro(char m) { xoro = m; }
void playerinfo::setID(int i) { ID = i; }
// Assign n,m,i to name, xoro and ID
std::string playerinfo::getName() const { return Name; }
char playerinfo::getxoro() const { return xoro; }
int playerinfo::getID() const { return ID; }
// The getters returns all the values}
