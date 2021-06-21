#include "BaseScreen.h"

BaseScreen::BaseScreen(TextureManager *tm, TextManager *ttm){
    printf("Creating base screen\n");
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
    printf("in init\n");
    this->key = key;

    texturem->getSize();
    std::cout << "key " << key << std::endl;

    baseImage.setTexture(texturem->getTexture(key));

    printf("getting texture done \n");

    // txt.setString(textm->getText(key));

    // texts.push_back(txt);

};