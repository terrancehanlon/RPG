#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <string>
// #include <unordered_map>
#include <vector>
#include "./Imports.h"

struct TextureItem {
    sf::Texture texture;
    std::string key;
};

class TextureManager {

    public:
        static TextureManager& getInstance();

        int addTexture(const std::string& key, const std::string& path);

        const sf::Texture& getTexture(const std::string& key) const;

        TextureManager();   
        ~TextureManager();
    private:
        std::vector<TextureItem> textures;
        // std::unordered_map<std::string, sf::Texture> textureMap;

};


#endif