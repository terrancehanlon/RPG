#ifndef RESOURCE_H
#define RESOURCE_H

#include "./Blood.h"

/*
    This class handles all resources:
        Blood.h
*/

class Resource {

    private:

    public:

        Blood *blood;
        int blood_x = sf::VideoMode::getDesktopMode().width / 4;
        int blood_y = sf::VideoMode::getDesktopMode().height / 4;

        Resource();
        ~Resource();

        void update(sf::Time dt);
        void render(sf::RenderWindow *window);
};

#endif