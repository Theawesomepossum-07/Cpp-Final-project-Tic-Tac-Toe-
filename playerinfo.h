#pragma once
// To prevent multiple inclusion
#include <string> 
// To use string
class playerinfo {
private:
    std::string Name;
    char xoro;
    int ID;
// Defined name, piece and id
public:
    playerinfo() { Name = " "; xoro = ' '; ID = 0; } // Default constructor
    playerinfo(std::string n, char m, int id); // Added std:: here
// Getters
    std::string getName() const;
    char getxoro() const;
    int getID() const;
// Setters
    void setName(std::string n);
    void setxoro(char m);
    void setID(int i);
};
