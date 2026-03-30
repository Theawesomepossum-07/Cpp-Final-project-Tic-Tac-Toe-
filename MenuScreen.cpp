#include "MenuScreen.h"
// Includes the header file
using namespace std; // To not use std multiple times

// Constructor: Initializes the menu screen with the given window dimensions
MenuScreen::MenuScreen(int width, int height) {
    windowWidth = width;
    windowHeight = height;
}

void MenuScreen::drawTitle() {
    
    cout << "==============================\n";
    cout << "         Tic-Tac-Toe!   \n";
    cout << "==============================\n";
} // Displays the title

void MenuScreen::drawStartButton() {
    
    cout << "          [Start Game]          \n";
    cout << "================================\n";
} // Displays the start of the game

string MenuScreen::promptPlayerName(int playerNumber) {
    string playerName;
    


cout << "Player " << playerNumber << ", please enter your name: ";
cin >> playerName;

return playerName;
} // For the playername to be inputted 

bool MenuScreen::isStartButtonClicked(int mouseX, int mouseY) {

return true;
} // To start the game
