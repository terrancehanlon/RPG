#include "StorageItem.h"


StorageItem::StorageItem(){
    name = "Storage Item";
};

void StorageItem::render(sf::RenderWindow *window, TextureManager *tm){
    // texture.loadFromFile(tm->getTexture("storage-item"));
    sprite.setTexture(tm->getTexture("storage-item"));
    window->draw(sprite);
}