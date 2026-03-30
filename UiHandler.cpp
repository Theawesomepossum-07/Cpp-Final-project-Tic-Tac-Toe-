#include "UiHandler.h"
// Includes the header file
using namespace std; // To not use std

UIHandler::UIHandler(int width, int height) {
    windowWidth = width;
    windowHeight = height;
    // Initializes the width and height
    // NEW: Load the font file!
    if (!font.loadFromFile("font.ttf")) {
        cout << "ERROR: Could not find font.ttf!\n"; // Incase the font is missing
    } else {
        resultText.setFont(font); // Applies the font
        resultText.setCharacterSize(65); // Big, bold text
        resultText.setFillColor(sf::Color::Yellow); // Yellow stands out against the white/black
        resultText.setOutlineColor(sf::Color::Black); // Black outline for constrast
        resultText.setOutlineThickness(4.0f); // Gives it a nice border
    }

    cout << "UiHandler upgraded to SFML!\n"; 
}

void UIHandler::drawGrid(sf::RenderWindow& window) {
    // Creates horizontal lines
    sf::RectangleShape hLine(sf::Vector2f(windowWidth, 5));
    hLine.setFillColor(sf::Color::White); // White grid lines
    hLine.setPosition(0, windowHeight / 3); // The 1st horizontal line
    window.draw(hLine); // Draws it
    hLine.setPosition(0, (windowHeight / 3) * 2); // The 2nd horizontal line
    window.draw(hLine); // Draws it

    // Vertical lines
    sf::RectangleShape vLine(sf::Vector2f(5, windowHeight));
    vLine.setFillColor(sf::Color::White); // For white grid lines
    vLine.setPosition(windowWidth / 3, 0); // For the 1st vertical line
    window.draw(vLine); // Draws it
    vLine.setPosition((windowWidth / 3) * 2, 0); // For the 2nd vertical line
    window.draw(vLine); // Draws it
}

void UIHandler::drawMarker(sf::RenderWindow& window, int gridIndex, char marker) {
    int squareSize = windowWidth / 3; // Width of each grid
    int col = gridIndex % 3; // Column index
    int row = gridIndex / 3; // Row index
    float startX = col * squareSize; // For the X position of the square
    float startY = row * squareSize; // For the Y position of the square

    if (marker == 'O') {
        sf::CircleShape circle(60.0f); // For displaying 'O'
        circle.setFillColor(sf::Color::Transparent); // Making it hollow
        circle.setOutlineThickness(10.0f); // Thickness of the 'O'
        circle.setOutlineColor(sf::Color::Blue); // Blue 'O' marker
        circle.setPosition(startX + 40, startY + 40); // Center inside the square
        window.draw(circle); // Draws the 'O'
    } 
    else if (marker == 'X') {
        sf::RectangleShape line1(sf::Vector2f(160.0f, 10.0f)); // Long thin rectangle
        line1.setFillColor(sf::Color::Red); // Red for 'X' mark
        line1.setOrigin(80.0f, 5.0f); // Center rotation point
        line1.setPosition(startX + 100, startY + 100); // Center inside the square
        line1.setRotation(45.0f); // Diagnol slash

        sf::RectangleShape line2(sf::Vector2f(160.0f, 10.0f));
        line2.setFillColor(sf::Color::Red);
        line2.setOrigin(80.0f, 5.0f);
        line2.setPosition(startX + 100, startY + 100);
        line2.setRotation(-45.0f);
// For the 2nd giagnol of the 'X' 
        window.draw(line1); // Draws the 1st slash
        window.draw(line2); // Draws the 2nd slash
    }
}

// NEW: Tell the text what to say, and draw it in the dead center!
void UIHandler::displayResult(sf::RenderWindow& window, string resultMessage) {
    resultText.setString(resultMessage);
    
    // Math to perfectly center the text box
    sf::FloatRect textRect = resultText.getLocalBounds();
    resultText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    resultText.setPosition(windowWidth / 2.0f, windowHeight / 2.0f);
    // Center the text
    window.draw(resultText); // Draws the centered message
}

int UIHandler::getSquareFromClick(Point clickPos)
{
    int squareWidth = windowWidth / 3;
    int squareHeight = windowHeight / 3;
    // Width and height of each grid square
    int col = clickPos.x / squareWidth;
    int row = clickPos.y / squareHeight;
    // Determines the clicked row and coloumn
    int index = (row * 3) + col;
    // Converts the row/coloumn to index
    if (index >= 0 && index <= 8) return index; // Validates it
    return -1;  // For invalid click(like outside the box)
}
