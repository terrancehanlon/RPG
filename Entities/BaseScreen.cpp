#include "BaseScreen.h"

BaseScreen::BaseScreen(){
    // this->key = key;
    //std::string key, TextureManager *texturem, TextManager *textm
    // baseImage.setTexture(texturem->getTexture(key));


    // txt.setString(textm->getText(key));

    // text.push_back(txt);

};

void BaseScreen::render(sf::RenderWindow *window){
    window->draw(baseImage);
    window->draw(txt);
}

void BaseScreen::update(sf::Time dt){
    //
}

void BaseScreen::init(std::string key, TextureManager *texturem, TextManager *textm){
    this->key = key;

    baseImage.setTexture(texturem->getTexture(key));


    txt.setString(textm->getText(key));

    texts.push_back(txt);

};