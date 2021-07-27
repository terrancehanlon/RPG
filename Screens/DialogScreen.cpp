#include "DialogScreen.h"
#include <iostream>

void DialogScreen::update(TextureManager *tm){
    
}

void DialogScreen::init(TextureManager *tm, TextManager *ttm){
    baseImage.setTexture(tm->getTexture("dialogBox1"));
    baseImage.setPosition(160.0f, 120.0f);
    baseImage.setScale(0.15, 0.15);
}
