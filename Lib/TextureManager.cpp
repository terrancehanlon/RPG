#include "TextureManager.h"

#include <iostream>

TextureManager::TextureManager(){}
TextureManager::~TextureManager(){}


void TextureManager::getSize(){
    std::cout << "size: " << this->textures.size() << std::endl;
}

const sf::Texture& TextureManager::getTexture(const std::string& key) const{
    // printf("getting texture\n");
    // auto it = this->textureMap.find(key);

    // if(it == textureMap.end()){
    //     std::cout << "Cant find key: " << key << std::endl;
    //     // printf("Cant find texture %s\n", key);
    //     return nullptr;
    // }

    // return it.second;
    for(auto& x : textures){
        if(x.key == key){
            // printf("key found\n");
            std::cout << key << " Found " << std::endl;
            return x.texture;
        }
    }

    // printf("Cant find\n");
    std::cout << "cant find: " << key << std::endl;
}

void TextureManager::removeTexture(const std::string& key) const{
    // textures.erase(std::remove_if(std::begin(textures), std::end(textures), [key](TextureItem t){
    //     return t.key == key;
    // }), std::end(textures));
}

void TextureManager::updateTexture(const std::string& key, std::string newPath){
    for(auto& t : textures){
        if(t.key == key){
            sf::Texture newTexture;
            newTexture.loadFromFile(newPath);
            t.texture = newTexture;
        }
    }
}


int TextureManager::addTexture(const std::string& id, const std::string& texturePath)
{
    // auto it = textureMap.find(id);
    // if(it != textureMap.end())
    // {
    //     printf("exists already\n");
    //     return -1;
    // }

    // std::unique_ptr<sf::Texture> texture = std::make_unique<sf::Texture>();
    sf::Texture texture;
    // texture.load 
    if(!texture.loadFromFile(texturePath))
    {
        printf("cant find path\n");
        return -1;
    }

    TextureItem t = {
        .texture = texture,
        .key = id
    };
    textures.push_back(t);
    // 
    // textureMap.emplace(id, texture);
    return 0;
}


TextureManager& TextureManager::getInstance()
{   
    static TextureManager instance;
    return instance;
}


