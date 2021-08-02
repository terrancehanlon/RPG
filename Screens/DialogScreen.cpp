#include "DialogScreen.h"
#include <iostream>

void DialogScreen::update(TextureManager *tm){
    float viewX = this->view->getCenter().x;
    float viewY = this->view->getCenter().y;

    baseImage.setPosition((viewX + viewSizeX - 110), viewY - 15);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        this->remove = true;
    }
    printPosition();
}

void DialogScreen::init(TextureManager *tm, TextManager *ttm){
    baseImage.setTexture(tm->getTexture("dialogBox1"));
    baseImage.setPosition(160.0f, 120.0f);
    baseImage.setScale(0.12, 0.12);

    this->lastViewX = this->view->getCenter().x;
    this->lastViewY = this->view->getCenter().y;
    this->viewSizeX = this->view->getSize().x; 
    this->viewSizeY = this->view->getSize().y;
}
