#pragma once 

#include <iostream>
#include <string>

class AssetManager{
    private:
    bool assetsLoaded;

    public:
    AssetManager();

    bool loadAllAssets();
    bool loadTexture(std::string filePath, std::string assetName);
    bool loadFont(std::string  fildePath);

    void clearAssets();
};
