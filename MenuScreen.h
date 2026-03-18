#pragma once

#include <iostream>
#include <string>

class MenuScreen {
private:
    //window dimensions for centering text
    int windowWidth;
    int windowHeight;

public:
    //constructor to initialize window size
    MenuScreen(int width, int height);

    void drawTitle();

    void drawStartButton();

    std::string promptPlayerName(int playerNumber);

    bool isStartButtonClicked(int mouseX, int mouseY);
};