#include "Storage.h"

Storage::Storage(){}


int Storage::getSize(){
    return inventory.size();
}

void Storage::render(sf::RenderWindow *window, TextureManager *tm){
    sprite.setTexture(tm->getTexture("storage-icon"));
    sprite.setScale(sf::Vector2f(0.5f, 0.5f));
}