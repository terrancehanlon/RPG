#ifndef STATE_H
#define STATE_H

#include "../Lib/Imports.h"

class State
{
    public:
        sf::RenderWindow *window;
        State();


        virtual void update(sf::Time dt) = 0;
        virtual void render() = 0;


};


#endif