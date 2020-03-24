#ifndef ROCK_H
#define ROCK_H
#include "../Lib/Imports.h"

class Rock{
    public:
        Rock();
        void update(sf::Time dt);
        void render(sf::RenderWindow *win);
};

#endif