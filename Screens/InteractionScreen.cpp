#include "InteractionScreen.h"


void InteractionScreen::update(TextureManager *tm){
    // printf()
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)){
        sf::Sprite s;
        s.setTexture(tm->getTexture("dialog1"));
        s.setPosition(baseImage.getPosition());
        s.setScale(0.15f, 0.15f);
        baseImage = s;
        tm->sw.diaglogActive = true;
        // sw->removeScreen("interaction-screen")
    }
}

void InteractionScreen::init(TextureManager *tm, TextManager *ttm){
    // this->key = key;
    baseImage.setTexture(tm->getTexture("interaction-screen"));
    baseImage.setScale(sf::Vector2f(0.5f,0.5f));
    font.loadFromFile("Assets/fonts/OpenSans-Bold.ttf");
    text.setFont(font);
    text.setString(ttm->getText("dialog1"));
    text.setPosition(baseImage.getPosition());
}   