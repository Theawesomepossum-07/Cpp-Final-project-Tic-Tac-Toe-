#include "AssetManager.h"

using namespace std;

AssetManager::AssetManager() {
    assetsLoaded = false;
    cout << "AssetManager initialized. Ready to load files.\n";
}

bool AssetManager::loadAllAssets() {
    cout << "[Assets] Starting to load all game resources...\n";
    
    // Loads the font file that is already in your repository
    loadFont("font.ttf");
    
    // Tries to load images (will just print a safe warning if you haven't made an images folder yet)
    loadTexture("images/board.png", "BoardBackground");
    loadTexture("images/playerX.png", "MarkerX");
    loadTexture("images/playerO.png", "MarkerO");
    
    assetsLoaded = true;
    cout << "[Assets] Loading sequence complete.\n";
    
    return assetsLoaded;
}

bool AssetManager::loadTexture(string filePath, string assetName) {
    sf::Texture tex;
    // SFML function to actually load the image file
    if (tex.loadFromFile(filePath)) {
        textures[assetName] = tex;
        cout << "[Assets] Loaded texture: " << assetName << " from " << filePath << "\n";
        return true; 
    }
    cout << "[Assets] Warning: Missing image " << filePath << " (Game will still run using drawn shapes)\n";
    return false;
}

bool AssetManager::loadFont(string filePath) {
    // SFML function to actually load the font file
    if (gameFont.loadFromFile(filePath)) {
        cout << "[Assets] Loaded font from " << filePath << "\n";
        return true;
    }
    cout << "[Assets] ERROR: Could not find font file at " << filePath << "\n";
    return false;
}

void AssetManager::clearAssets() {
    // Clears the map to free up RAM
    textures.clear();
    assetsLoaded = false;
    cout << "[Assets] All resources cleared from memory.\n";
}