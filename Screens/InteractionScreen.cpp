#include "InteractionScreen.h"


void InteractionScreen::update(TextureManager *tm){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)){
        printf("changing texture\n");
        sf::Sprite s;
        s.setTexture(tm->getTexture("dialog1"));
        s.setPosition(baseImage.getPosition());
        s.setScale(0.15f, 0.15f);
        baseImage = s;
        tm->sw.diaglogActive = true;
    }

}