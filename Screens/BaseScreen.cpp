#include "BaseScreen.h"

BaseScreen::BaseScreen(TextureManager *tm, TextManager *ttm, sf::View *view){
    this->ttm = ttm;
    this->view = view;
};

void BaseScreen::render(sf::RenderWindow *window){
    window->draw(baseImage);
    window->draw(text);
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

void BaseScreen::printPosition(){
    std::cout << "X: " <<  baseImage.getPosition().x << std::endl << "Y: " << baseImage.getPosition().y << std::endl; 
}

BaseScreen::BaseScreen(){}


