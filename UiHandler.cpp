#include "UiHandler.h"

using namespace std;

// Constructor: Sets up the initial window dimensions
UIHandler::UIHandler(int width, int height) {
    windowWidth = width;
    windowHeight = height;
    cout << "UIHandler initialized with window size: " 
         << windowWidth << "x" << windowHeight << "\n";
}

// Draws the physical 3x3 grid lines on the screen
void UIHandler::drawGrid() {
    // TODO: Implement graphics library line-drawing code
    cout << "[UI] Drawing the Tic-Tac-Toe Grid...\n";
}

// Renders an 'X' or 'O' marker at the specified grid index
void UIHandler::drawMarker(int gridIndex, char marker) {
    // TODO: Implement graphics library image/text rendering
    cout << "[UI] Drawing '" << marker << "' at grid index: " << gridIndex << "\n";
}

// Shows the final winner or draw text at the end of the match
void UIHandler::displayResult(string resultMessage) {
    // TODO: Implement graphics library text rendering
    cout << "\n==============================\n";
    cout << "GAME OVER: " << resultMessage << "\n";
    cout << "==============================\n";
}

// Translates raw pixel coordinates into a grid index (0-8)
int UIHandler::getSquareFromClick(Point clickPos) {
    // Calculate the width and height of a single square
    int squareWidth = windowWidth / 3;
    int squareHeight = windowHeight / 3;

    // Determine the column and row based on the click coordinates
    int col = clickPos.x / squareWidth;
    int row = clickPos.y / squareHeight;

    // Convert 2D row/col into a 1D array index
    int index = (row * 3) + col;
    
    // Validate that the click is within the board boundaries
    if (index >= 0 && index <= 8) {
        return index;
    }
    
    // Return -1 if the click was out of bounds
    return -1; 
}