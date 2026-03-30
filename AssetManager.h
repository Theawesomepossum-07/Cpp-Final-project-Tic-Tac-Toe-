#pragma once  // To prevent multiple inclusion

#include <iostream> // To follow commands
#include <string> // To use string
#include <map> // To store texture 
#include <SFML/Graphics.hpp> // To use the SFML graphics class

class AssetManager{
private:
    bool assetsLoaded;
    // Map to store textures by name, and a Font object
    std::map<std::string, sf::Texture> textures;
    sf::Font gameFont;
// All the required data type are defined
public:
    AssetManager(); // Constructor

    bool loadAllAssets();
    bool loadTexture(std::string filePath, std::string assetName);
    bool loadFont(std::string filePath);
// All the bool function are defined
    void clearAssets(); // Created to clear memory
};
