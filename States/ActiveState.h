#ifndef ACTIVE_STATE
#define ACTIVE_STATE

// #include "State.h"
#include "../Lib/Imports.h"
#include "../Entities/Entity.h"
#include <string>
#include <stack>
#include "../Zones/Zone.h"
class ActiveState : public State {

    public:

        //player instance
        Entity *player;
        std::stack<Zone*> zones;
        ActiveState(sf::RenderWindow *window);

        void initState();

        void update(sf::Time dt);
        void render();

};

#endif