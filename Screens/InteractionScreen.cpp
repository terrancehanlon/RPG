#include "InteractionScreen.h"
#include "DialogScreen.h"


void InteractionScreen::update(TextureManager *tm){
    // printf()
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)){
        DialogScreen *ds = new DialogScreen(tm, ttm, view);
        ds->key = "dialogBox1";
        this->sm->addScreen(ds);
        tm->sw.diaglogActive = true;        
    }
}

void InteractionScreen::init(TextureManager *tm, TextManager *ttm){
    this->key = "interaction-screen";
    this->tm = tm;
    baseImage.setTexture(tm->getTexture("interaction-screen"));
    baseImage.setScale(sf::Vector2f(0.5f,0.5f));
    font.loadFromFile("Assets/fonts/OpenSans-Bold.ttf");
    text.setFont(font);
    text.setString(ttm->getText("dialog1"));
    text.setScale(0.1f, 0.1f);
    text.setPosition(baseImage.getPosition());
    text.setPosition(text.getPosition().x + 55, text.getPosition().y + 55);
}   