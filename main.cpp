#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "UiHandler.h"

using namespace std;

int main() {
    sf::RenderWindow window(sf::VideoMode(600, 600, sf::VideoMode::getDesktopMode().bitsPerPixel), "Tic-Tac-Toe: Final UI Test");
    sf::err().rdbuf(NULL);

    UIHandler ui(600, 600);

    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char currentTurn = 'X';
    
    // NEW: Game State Variables
    bool isGameOver = false;
    string winMessage = "";

    cout << "SFML Window created successfully!\n";
    cout << "Click to play. Press SPACEBAR to test the Game Over screen!\n";

    while (window.isOpen()) {
        sf::Event event;
        
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            
            // NEW: Press Spacebar to force a win screen!
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space && !isGameOver) {
                    isGameOver = true;
                    winMessage = "Player " + string(1, currentTurn) + " Wins!";
                    cout << "Game Over triggered!\n";
                }
            }
            
            // Only allow clicking if the game is NOT over
            if (event.type == sf::Event::MouseButtonPressed && !isGameOver) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    Point clickPos;
                    clickPos.x = event.mouseButton.x;
                    clickPos.y = event.mouseButton.y;

                    int clickedSquare = ui.getSquareFromClick(clickPos);
                    
                    if (clickedSquare != -1 && board[clickedSquare] == ' ') {
                        board[clickedSquare] = currentTurn;
                        
                        if (currentTurn == 'X') {
                            currentTurn = 'O';
                        } else {
                            currentTurn = 'X';
                        }
                    }
                }
            }
        }

        window.clear(sf::Color::Black);
        ui.drawGrid(window);

        for (int i = 0; i < 9; i++) {
            if (board[i] != ' ') { 
                ui.drawMarker(window, i, board[i]); 
            }
        }

        // NEW: If the game is over, draw the massive text over the board!
        if (isGameOver) {
            ui.displayResult(window, winMessage);
        }

        window.display(); 
    }

    return 0;
}