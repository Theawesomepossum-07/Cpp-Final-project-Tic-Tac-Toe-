#include "AssetManager.h"

using namespace std;

// Constructor: Sets the initial state before any files are loaded
AssetManager::AssetManager() {
    assetsLoaded = false;
    cout << "AssetManager initialized. Ready to load files.\n";
}

// Master function that calls the individual loading functions for the required files
bool AssetManager::loadAllAssets() {
    cout << "[Assets] Starting to load all game resources...\n";
    
    // Example paths for where the game images and fonts will be stored
    loadTexture("images/board.png", "BoardBackground");
    loadTexture("images/playerX.png", "MarkerX");
    loadTexture("images/playerO.png", "MarkerO");
    loadFont("fonts/gamefont.ttf");
    
    assetsLoaded = true;
    cout << "[Assets] All game resources loaded successfully.\n";
    
    return assetsLoaded;
}

// Handles pulling an image file from the project folder and storing it
bool AssetManager::loadTexture(string filePath, string assetName) {
    // TODO: Implement graphics library code to load the image file
    cout << "[Assets] Loaded texture: " << assetName << " from " << filePath << "\n";
    return true; 
}

// Handles pulling a font file from the project folder for text rendering
bool AssetManager::loadFont(string filePath) {
    // TODO: Implement graphics library code to load the font file
    cout << "[Assets] Loaded font from " << filePath << "\n";
    return true;
}

// Destroys the loaded assets to prevent memory leaks when the application closes
void AssetManager::clearAssets() {
    // TODO: Implement graphics library code to destroy textures and free memory
    assetsLoaded = false;
    cout << "[Assets] All resources cleared from memory.\n";
}