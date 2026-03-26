#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <string>
#include "UiHandler.h"
#include "GameManager.h"
#include "playerinfo.h"
#include "scores.h"

using namespace std;

int main() {
    // Mute SFML's internal error spam (like the joystick warnings)
    sf::err().rdbuf(NULL);
    
    // 1. Create the Window and UI
    sf::RenderWindow window(sf::VideoMode(600, 600, sf::VideoMode::getDesktopMode().bitsPerPixel), "Tic-Tac-Toe: Final Version");
    UIHandler ui(600, 600);

    // 2. Initialize Core Logic and Data tracking
    GameManager game;
    playerinfo p1("Player 1", 'X', 1);
    playerinfo p2("Player 2", 'O', 2);
    scores gameScore(0, 0, 0); // Tracks wins for P1, P2, and Ties

    cout << "Game started! Scores are active.\n";

    // 3. The Main Loop
    while (window.isOpen()) {
        sf::Event event;
        
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            
            // Only handle clicks if game isn't currently showing a finished state
            if (event.type == sf::Event::MouseButtonPressed && !game.isFinished()) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    Point clickPos;
                    clickPos.x = event.mouseButton.x;
                    clickPos.y = event.mouseButton.y;

                    int clickedSquare = ui.getSquareFromClick(clickPos);
                    
                    if (clickedSquare != -1) {
                        int row = clickedSquare / 3;
                        int col = clickedSquare % 3;

                        // Process the turn
                        game.playTurn(row, col);

                        // --- NEW: SCORE INTEGRATION ---
                        // Check immediately after turn if that move ended the game
                        if (game.isFinished()) {
                            char result = game.getResult(); // 'X', 'O', or 'D'
                            
                            if (result == p1.getxoro()) {
                                gameScore.addwin(1);
                                cout << p1.getName() << " scored a point!\n";
                            } else if (result == p2.getxoro()) {
                                gameScore.addwin(2);
                                cout << p2.getName() << " scored a point!\n";
                            } else if (result == 'D') {
                                gameScore.addDraw();
                                cout << "Scoreboard updated for a Tie.\n";
                            }
                            
                            // Print the current standings to the terminal
                            gameScore.printscore();
                        }
                    }
                }
            }
            
            // --- OPTIONAL: Press 'R' to reset board after a win ---
            if (game.isFinished() && event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::R) {
                    game.reset(); // Assuming GameManager has a reset function
                }
            }
        }

        // 4. Drawing Logic
        window.clear(sf::Color::Black);
        ui.drawGrid(window);

        // 5. Draw the pieces from the board
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

        // 6. Draw Victory Screen
        if (game.isFinished()) {
            string winMessage;
            char res = game.getResult();
            
            if (res == 'D') {
                // Notice the \n right after Tie!
                winMessage = "It's a Tie!\n(Press R to Reset)"; 
            } else {
                string name = (res == 'X') ? p1.getName() : p2.getName();
                // Notice the \n right after Wins!
                winMessage = name + " Wins!\n(Press R to Reset)";
            }
            ui.displayResult(window, winMessage);
        }

        window.display(); 
    }

    // FINAL STEP: Print final stats to terminal upon exit
    cout << "\n--- FINAL TOURNAMENT RESULTS ---\n";
    gameScore.printscore();

    return 0;
}