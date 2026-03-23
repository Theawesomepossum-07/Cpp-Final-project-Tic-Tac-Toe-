#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

int main() {
    // 1. Create a 600x600 window with the title of your game
    sf::RenderWindow window(sf::VideoMode(600, 600), "Tic-Tac-Toe Visual Test");

    cout << "SFML Window created successfully!\n";

    // 2. The main Game Loop (keeps the window open until you close it)
    while (window.isOpen()) {
        sf::Event event;
        
        // Listen for user inputs (like clicking the 'X' button to close)
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // 3. Clear the screen to a solid color (Black)
        window.clear(sf::Color::Black);
        
        // (This is where your UIHandler.drawGrid() will eventually go!)

        // 4. Tell the screen to update and show what we drew
        window.display(); 
    }

    return 0;
}