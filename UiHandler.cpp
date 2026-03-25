#include "UiHandler.h"

using namespace std;

UIHandler::UIHandler(int width, int height) {
    windowWidth = width;
    windowHeight = height;
    
    // NEW: Load the font file!
    if (!font.loadFromFile("font.ttf")) {
        cout << "ERROR: Could not find font.ttf!\n";
    } else {
        resultText.setFont(font);
        resultText.setCharacterSize(65); // Big, bold text
        resultText.setFillColor(sf::Color::Yellow); // Yellow stands out against the white/black
        resultText.setOutlineColor(sf::Color::Black);
        resultText.setOutlineThickness(4.0f); // Gives it a nice border
    }

    cout << "UiHandler upgraded to SFML!\n";
}

void UIHandler::drawGrid(sf::RenderWindow& window) {
    // Horizontal lines
    sf::RectangleShape hLine(sf::Vector2f(windowWidth, 5));
    hLine.setFillColor(sf::Color::White);
    hLine.setPosition(0, windowHeight / 3);
    window.draw(hLine);
    hLine.setPosition(0, (windowHeight / 3) * 2);
    window.draw(hLine);

    // Vertical lines
    sf::RectangleShape vLine(sf::Vector2f(5, windowHeight));
    vLine.setFillColor(sf::Color::White);
    vLine.setPosition(windowWidth / 3, 0);
    window.draw(vLine);
    vLine.setPosition((windowWidth / 3) * 2, 0);
    window.draw(vLine);
}

void UIHandler::drawMarker(sf::RenderWindow& window, int gridIndex, char marker) {
    int squareSize = windowWidth / 3;
    int col = gridIndex % 3;
    int row = gridIndex / 3;
    float startX = col * squareSize;
    float startY = row * squareSize;

    if (marker == 'O') {
        sf::CircleShape circle(60.0f);
        circle.setFillColor(sf::Color::Transparent);
        circle.setOutlineThickness(10.0f);
        circle.setOutlineColor(sf::Color::Blue);
        circle.setPosition(startX + 40, startY + 40);
        window.draw(circle);
    } 
    else if (marker == 'X') {
        sf::RectangleShape line1(sf::Vector2f(160.0f, 10.0f));
        line1.setFillColor(sf::Color::Red);
        line1.setOrigin(80.0f, 5.0f);
        line1.setPosition(startX + 100, startY + 100);
        line1.setRotation(45.0f);

        sf::RectangleShape line2(sf::Vector2f(160.0f, 10.0f));
        line2.setFillColor(sf::Color::Red);
        line2.setOrigin(80.0f, 5.0f);
        line2.setPosition(startX + 100, startY + 100);
        line2.setRotation(-45.0f);

        window.draw(line1);
        window.draw(line2);
    }
}

// NEW: Tell the text what to say, and draw it in the dead center!
void UIHandler::displayResult(sf::RenderWindow& window, string resultMessage) {
    resultText.setString(resultMessage);
    
    // Math to perfectly center the text box
    sf::FloatRect textRect = resultText.getLocalBounds();
    resultText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    resultText.setPosition(windowWidth / 2.0f, windowHeight / 2.0f);
    
    window.draw(resultText);
}

int UIHandler::getSquareFromClick(Point clickPos) {
    int squareWidth = windowWidth / 3;
    int squareHeight = windowHeight / 3;
    int col = clickPos.x / squareWidth;
    int row = clickPos.y / squareHeight;
    int index = (row * 3) + col;
    
    if (index >= 0 && index <= 8) return index;
    return -1; 
}