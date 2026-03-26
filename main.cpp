#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <string>

// Include ALL your custom classes
#include "UiHandler.h"
#include "GameManager.h"
#include "playerinfo.h"
#include "scores.h"
#include "AssetManager.h"
#include "MenuScreen.h"
#include "MoveValidator.h"

using namespace std;

int main() {
    // Mute SFML's internal error spam
    sf::err().rdbuf(NULL);

    // ==========================================
    // REQUIREMENT 1: Use MenuScreen
    // ==========================================
    MenuScreen menu(600, 600);
    menu.drawTitle();
    string name1 = menu.promptPlayerName(1);
    string name2 = menu.promptPlayerName(2);
    
    // ==========================================
    // REQUIREMENT 2: Use AssetManager
    // ==========================================
    AssetManager assets;
    assets.loadAllAssets(); // Loads font.ttf and checks for images

    // Initialize Game Objects
    sf::RenderWindow window(sf::VideoMode(600, 600, sf::VideoMode::getDesktopMode().bitsPerPixel), "Tic-Tac-Toe: Final Integration");
    UIHandler ui(600, 600);
    GameManager game;
    MoveValidator validator; // REQUIREMENT 3: Initialize MoveValidator
    
    playerinfo p1(name1, 'X', 1);
    playerinfo p2(name2, 'O', 2);
    scores gameScore(0, 0, 0);

    cout << "\nGame started! Click the board to play.\n";

    // Main Game Loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();

            if (event.type == sf::Event::MouseButtonPressed && !game.isFinished()) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    Point clickPos;
                    clickPos.x = event.mouseButton.x;
                    clickPos.y = event.mouseButton.y;

                    int clickedSquare = ui.getSquareFromClick(clickPos);
                    
                    if (clickedSquare != -1) {
                        int row = clickedSquare / 3;
                        int col = clickedSquare % 3;
                        
                        game.playTurn(row, col);

                        // ==========================================
                        // REQUIREMENT 3: Use MoveValidator for Logic
                        // ==========================================
                        const GameBoard& currentBoard = game.getBoard();
                        
                        if (validator.hasWinner(currentBoard, 'X')) {
                            gameScore.addwin(1);
                            cout << p1.getName() << " scored a point!\n";
                            gameScore.printscore();
                        } 
                        else if (validator.hasWinner(currentBoard, 'O')) {
                            gameScore.addwin(2);
                            cout << p2.getName() << " scored a point!\n";
                            gameScore.printscore();
                        } 
                        else if (validator.isDrawGame(currentBoard)) {
                            gameScore.addDraw();
                            cout << "Scoreboard updated for a Tie.\n";
                            gameScore.printscore();
                        }
                    }
                }
            }

            if (game.isFinished() && event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::R) game.reset();
            }
        }

        // Drawing Phase
        window.clear(sf::Color::Black);
        ui.drawGrid(window);

        const GameBoard& currentBoard = game.getBoard();
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                char marker = currentBoard.getValue(r, c);
                if (marker == 'X' || marker == 'O') {
                    int index = (r * 3) + c;
                    ui.drawMarker(window, index, marker);
                }
            }
        }

        if (game.isFinished()) {
            string winMessage;
            if (validator.isDrawGame(currentBoard) && !validator.hasWinner(currentBoard, 'X') && !validator.hasWinner(currentBoard, 'O')) {
                winMessage = "It's a Tie!\n(Press R to Reset)"; 
            } else {
                string winnerName = validator.hasWinner(currentBoard, 'X') ? p1.getName() : p2.getName();
                winMessage = winnerName + " Wins!\n(Press R to Reset)";
            }
            ui.displayResult(window, winMessage);
        }

        window.display();
    }

    assets.clearAssets(); // Clean up memory on exit
    
    cout << "\n--- FINAL TOURNAMENT RESULTS ---\n";
    gameScore.printscore();

    return 0;
}