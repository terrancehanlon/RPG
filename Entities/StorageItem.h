#ifndef STORAGEITEM_H
#define STORAGEITEM_h

#pragma

#include "../Lib/Imports.h"
#include "../Lib/TextureManager.h"
#include <string>

class StorageItem{

    protected:
        std::string name;
        sf::Texture texture;
        sf::Sprite sprite;
    
    public:
        StorageItem();
        
        void render(sf::RenderWindow *window, TextureManager *tm);


};

#endif