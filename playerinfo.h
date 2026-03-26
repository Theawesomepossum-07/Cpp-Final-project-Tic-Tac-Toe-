#pragma once
#include <string>
using namespace std;
class playerinfo
 {
private:
    string Name;
    char xoro;  
    int ID; 

public:
    playerinfo(){Name = " "; xoro=' ';ID=0;};
    playerinfo(string, char, int);

    string getName() const;
    char getxoro() const;
    int getID() const;

    void setName(string);
    void setMarker(char);
    void setID(int);
    void setxoro(char m);
};