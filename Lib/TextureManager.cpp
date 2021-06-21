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
            // std::cout << key << std::endl;
            return x.texture;
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
    // printf()
    printf("returning instance\n");
    static TextureManager instance;
    return instance;
}


