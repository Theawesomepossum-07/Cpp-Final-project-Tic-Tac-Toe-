#pragma once
// To prevent multiple inclusion
#include <SFML/Graphics.hpp> // To use the SFML graphics
#include <iostream> // To follow the commands
#include <string> // To use string

struct Point 
{
    int x; 
    int y;
}; // The x and y coordinate for the mouse click position

class UIHandler {
private:
    int windowWidth; 
    int windowHeight;
    // Defined for the width and height of the game in pixels
    // NEW: SFML objects to handle the font and text
    sf::Font font;
    sf::Text resultText;
public:
    UIHandler(int width, int height); // Constructor
    void drawGrid(sf::RenderWindow& window); // To draw the tic-tac-toe
    void drawMarker(sf::RenderWindow& window, int gridIndex, char marker); // To draw an X or O
    void displayResult(sf::RenderWindow& window, std::string resultMessage); // To display the result

    int getSquareFromClick(Point clickPos); // For the mouse click position
};
