#ifndef ACTIVE_STATE
#define ACTIVE_STATE

// #include "State.h"
#include "../Entities/Entity.h"
#include <string>

class ActiveState : public State {

    public:

        //player instance
        Entity *player;
        ActiveState(sf::RenderWindow *window);

        void initState();

        void update(sf::Time dt);
        void render();

};

#endif