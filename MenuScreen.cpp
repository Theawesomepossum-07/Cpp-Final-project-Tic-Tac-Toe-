#include "MenuScreen.h"

using namespace std;

// Constructor: Initializes the menu screen with the given window dimensions
MenuScreen::MenuScreen(int width, int height) {
    windowWidth = width;
    windowHeight = height;
}

void MenuScreen::drawTitle() {
    
    cout << "==============================\n";
    cout << "         Tic-Tac-Toe!   \n";
    cout << "==============================\n";
}

void MenuScreen::drawStartButton() {
    
    cout << "          [Start Game]          \n";
    cout << "================================\n";
}

string MenuScreen::promptPlayerName(int playerNumber) {
    string playerName;
    


cout << "Player " << playerNumber << ", please enter your name: ";
cin >> playerName;

return playerName;
}

bool MenuScreen::isStartButtonClicked(int mouseX, int mouseY) {

return true;
}