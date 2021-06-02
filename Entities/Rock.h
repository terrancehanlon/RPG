#ifndef ROCK_H
#define ROCK_H
// #include "../Lib/Imports.h"
#include "../Lib/TextureManager.h"

class Rock{
    public:
        Rock();
        void update(sf::Time dt);
        void render(sf::RenderWindow *win);
};

#endif