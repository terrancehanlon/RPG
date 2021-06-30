#include "BaseScreen.h"

BaseScreen::BaseScreen(TextureManager *tm, TextManager *ttm){
    // this->key = key;
    this->ttm = ttm;
    //std::string key, TextureManager *texturem, TextManager *textm
    // baseImage.setTexture(texturem->getTexture(key));


    // txt.setString(textm->getText(key));

    // text.push_back(txt);

};

void BaseScreen::render(sf::RenderWindow *window){
    // std::cout << "rendering screen" << std::endl;
    // baseImage.setPosition(160, 150); 
    // std::cout << baseImage.getPosition().y << std::endl;
    window->draw(baseImage);
    window->draw(text);
    // for(auto& s : images){
    //     window->draw(s);
    // }
}

void BaseScreen::update(TextureManager *tm){
    printf("update in base\n");
}

void BaseScreen::init(TextureManager *texturem, TextManager *textm){
    printf("in init base\n");
};

void BaseScreen::setPosition(float x, float y){
    baseImage.setPosition(sf::Vector2f(x,y));
}

BaseScreen::BaseScreen(){}