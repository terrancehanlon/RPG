#ifndef BASESCREEN_H
#define BASESCREEN_H

#include "../Lib/Imports.h"
#include "../Lib/TextManager.h"
#include "../Lib/TextureManager.h"
#include <vector>
#include <string>
#include <iostream>

class BaseScreen {


    protected:
        sf::Sprite baseImage; //base image of the screen
        sf::Texture texture;
        std::vector<sf::Text> texts;
        sf::Font font;
        sf::Text txt;

    public:
        std::string key;
        BaseScreen(TextureManager *tm, TextManager *ttm);

        void update(sf::Time dt);
        void render(sf::RenderWindow *window);

        void init(std::string key, TextureManager *texturem, TextManager *textm);
        void setPosition(float x, float y);




};

#endif