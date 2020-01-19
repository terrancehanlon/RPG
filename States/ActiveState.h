#ifndef ACTIVE_STATE
#define ACTIVE_STATE

// #include "State.h"
#include "../Lib/Imports.h"
#include "../Entities/Entity.h"
#include <string>
#include <stack>
#include "../Zones/Zone.h"
#include "../Entities/Movement.h"
class ActiveState : public State {

    public:

        //player instance
        Entity *player;
        lua_State *L;
        std::stack<Zone*> zones;
        ActiveState(sf::RenderWindow *window);
        Movement *movementComp;

        float getPlayerX();
        float getPlayerY();

        int getIntField(lua_State *L, const char* key);
        std::string getStringField(lua_State *L, const char* key);

        sf::View *view;

        void initState();

        void update(sf::Time dt);
        void render();

};

#endif