#pragma once
#include <string>

class playerinfo {
private:
    std::string Name;
    char xoro;
    int ID;

public:
    playerinfo() { Name = " "; xoro = ' '; ID = 0; }
    playerinfo(std::string n, char m, int id); // Added std:: here

    std::string getName() const;
    char getxoro() const;
    int getID() const;

    void setName(std::string n);
    void setxoro(char m);
    void setID(int i);
};