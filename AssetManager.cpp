#include "AssetManager.h" // Includes the header file

using namespace std; // To not use cout and cin 

AssetManager::AssetManager() {
    assetsLoaded = false;
    cout << "AssetManager initialized. Ready to load files.\n";
} // Displays message to lad files when needed

bool AssetManager::loadAllAssets() {
    cout << "[Assets] Starting to load all game resources...\n";
    
    // Loads the font file that is already in your repository
    loadFont("font.ttf");
    
    // Tries to load images used for the graphics but instead draws the X' and O's
    loadTexture("images/board.png", "BoardBackground");
    loadTexture("images/playerX.png", "MarkerX");
    loadTexture("images/playerO.png", "MarkerO");
    
    assetsLoaded = true;
    cout << "[Assets] Loading sequence complete.\n";
    
    return assetsLoaded; // Returns the assetsLoaded
} 

bool AssetManager::loadTexture(string filePath, string assetName) {
    sf::Texture tex;
    // SFML function to actually load the image file
    if (tex.loadFromFile(filePath)) // Loads the texture from the given file path 
    {
        textures[assetName] = tex; // Stores the loaded texture in the map using assestname as the key
        cout << "[Assets] Loaded texture: " << assetName << " from " << filePath << "\n";
        return true; // The succes message is then displayed
    }
    cout << "[Assets] Warning: Missing image " << filePath << " (Game will still run using drawn shapes)\n";
    return false; // The failure message is displayed
}

bool AssetManager::loadFont(string filePath) // To load the font from the file
{
    // SFML function to actually load the font file
    if (gameFont.loadFromFile(filePath)) {
        cout << "[Assets] Loaded font from " << filePath << "\n";
        return true; // Displays the success message 
    }
    cout << "[Assets] ERROR: Could not find font file at " << filePath << "\n";
    return false; // Displays the error message
}

void AssetManager::clearAssets()
{
    // Clears the map to free up RAM
    textures.clear(); // Removes texture
    assetsLoaded = false; // Resets to check 
    cout << "[Assets] All resources cleared from memory.\n"; // Displays the resource is cleared
}
