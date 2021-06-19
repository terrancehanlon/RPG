#include "Menu.h"

Menu::Menu(TextureManager *tm){
    // sf::Font font;
    if (!font.loadFromFile("Assets/fonts/OpenSans-Bold.ttf"))
    {
        // error...
        printf("Cant load font in menu\n");
    }else{
        background.setTexture(tm->getTexture("menu-background"));
        sf::Text text;
        text.setFont(font);
        text.setString("Welcome\nPress 1 to continue\nPress 2 to exit\n");
        text.setFillColor(sf::Color::Red);
        text.setPosition(150.0f, 150.0f);
        // TextItem textItem;
        // textItem.text = text;
        // textItem.x = 150;
        // textItem.y = 150;

        this->texts.push_back(text);
    }


};

void Menu::update(sf::Time dt){
    // background.update(dt);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)){
        this->stateFinished = true;
    }
};

void Menu::render(sf::RenderWindow *window){
    for(auto t : this->texts){
        window->draw(t);
    }
}