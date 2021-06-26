#include "InteractionScreen.h"


void InteractionScreen::update(TextureManager *tm){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)){
        this->baseImage.setTexture(tm->getTexture("interaction-screen-select-1"));
    }

    // printf("update in derived\n");
}