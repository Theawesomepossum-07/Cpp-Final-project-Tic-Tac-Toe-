#pragma once 

#include <iostream>
#include <string>
#include <map>
#include <SFML/Graphics.hpp>

class AssetManager{
private:
    bool assetsLoaded;
    // Map to store textures by name, and a Font object
    std::map<std::string, sf::Texture> textures;
    sf::Font gameFont;

public:
    AssetManager();

    bool loadAllAssets();
    bool loadTexture(std::string filePath, std::string assetName);
    bool loadFont(std::string filePath);

    void clearAssets();
};