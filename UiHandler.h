#pragma once

#include <iostream>
#include <string>

// Structure to hold 2D coordinates
struct Point {
    int x;
    int y;
};

class UIHandler {
private:
    // Window dimensions
    int windowWidth;
    int windowHeight;

public:
    // Constructor to initialize window size
    UIHandler(int width, int height);

    // Core drawing functions
    void drawGrid();
    void drawMarker(int gridIndex, char marker);
    
    // Displays the final game result
    void displayResult(std::string resultMessage);

    // Translates mouse click coordinates into a grid index (0-8)
    int getSquareFromClick(Point clickPos);
};