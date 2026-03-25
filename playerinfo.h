#pragma once

#include <string>

class playerinfo
{
private:
    std::string Name;
    char xoro;
    int ID;

public:
    playerinfo() : Name(" "), xoro(' '), ID(0) {}
    playerinfo(std::string, char, int);

    std::string getName() const;
    char getxoro() const;
    int getID() const;

    void setName(std::string);
    void setMarker(char);
    void setID(int);
};
