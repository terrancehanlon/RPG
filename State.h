#ifndef STATE_H
#define STATE_H

#include "Entity.h"

class State
{
    public:
        sf::RenderWindow *window;
        State(sf::RenderWindow *window);


        virtual void update(sf::Time dt) = 0;
        virtual void render() = 0;


};


#endif