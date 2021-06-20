#ifndef BASESCREEN_H
#define BASESCREEN_H

#include "../Lib/Imports.h"
#include "../Lib/TextManager.h"
#include "../Lib/TextureManager.h"
#include <vector>
#include <string>

class BaseScreen {


    protected:
        sf::Sprite baseImage; //base image of the screen
        sf::Texture texture;
        std::vector<sf::Text> texts;
        sf::Font font;
        std::string key;
        sf::Text txt;

    public:
        BaseScreen();

        void update(sf::Time dt);
        void render(sf::RenderWindow *window);

        void init(std::string key, TextureManager *texturem, TextManager *textm);




};

#endif