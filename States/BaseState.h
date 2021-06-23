#ifndef BaseState_h
#define BaseState_h

#include "../Lib/Imports.h"

class BaseState{

    protected:
        int x = 5;
    
    public:
        BaseState();

        virtual void render(sf::RenderWindow *window) = 0;
        virtual void update(sf::Time dt) = 0;
        virtual void init() = 0;

         bool stateFinished = false;

};


#endif