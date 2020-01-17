#ifndef ZONE_H
#define ZONE_H

#include "../Lib/Imports.h"

class Zone {

    private:
        sf::Texture texture;
        sf::Image image;
        sf::Sprite sprite;

    public:
        Zone();
        ~Zone();
        void update(sf::Time deltaTime, float x, float y, sf::RenderWindow *window);
        void draw(sf::RenderWindow *window);

};

#endif