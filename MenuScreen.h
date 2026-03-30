#pragma once
// To prevent multiple inclusion
#include <iostream> // To follow commands
#include <string> // To use string

class MenuScreen {
private:
    //window dimensions for centering text
    int windowWidth;
    int windowHeight;
// Defined to set the game in the center
public:
    MenuScreen(int width, int height); // Constructor

    void drawTitle(); 
    void drawStartButton();
// To display the tile and start of the game
    std::string promptPlayerName(int playerNumber);
// For playername
    bool isStartButtonClicked(int mouseX, int mouseY); // To start the game
};
