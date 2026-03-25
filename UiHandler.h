#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

struct Point {
    int x;
    int y;
};

class UIHandler {
private:
    int windowWidth;
    int windowHeight;
    
    // NEW: SFML objects to handle the font and text
    sf::Font font;
    sf::Text resultText;

public:
    UIHandler(int width, int height);

    void drawGrid(sf::RenderWindow& window);
    void drawMarker(sf::RenderWindow& window, int gridIndex, char marker);
    void displayResult(sf::RenderWindow& window, std::string resultMessage);

    int getSquareFromClick(Point clickPos);
};