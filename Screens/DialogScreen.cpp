#include "DialogScreen.h"
#include <iostream>

void DialogScreen::update(TextureManager *tm){
    // this->view->getCenter().x
    int viewX = this->view->getCenter().x;
    int viewY = this->view->getCenter().y;
    int viewSizeX = this->view->getSize().x; 
    int viewSizeY = this->view->getSize().y;

    printf("setting position\n");
    baseImage.setPosition((viewX + viewSizeX - 110), viewY - 15);
    // getScree
    printPosition();
}

void DialogScreen::init(TextureManager *tm, TextManager *ttm){
    baseImage.setTexture(tm->getTexture("dialogBox1"));
    baseImage.setPosition(160.0f, 120.0f);
    baseImage.setScale(0.12, 0.12);
}
