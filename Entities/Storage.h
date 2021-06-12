#ifndef STORAGE_H
#define STORAGE_H

// #include "../Lib/Imports.h"
#include "StorageItem.h"

#include <vector>

class Storage {

    protected: 
        std::vector<StorageItem> inventory;
        int count = 0;
        sf::Sprite sprite;
    
    public:
        Storage();

        int getSize();

        void render(sf::RenderWindow *window, TextureManager *tm);



};


#endif