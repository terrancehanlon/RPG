#ifndef ACTIVE_STATE
#define ACTIVE_STATE

// #include "State.h"
#include "../Entities/Entity.h"
#include <string>
#include <stack>
#include "../Zones/Zone.h"
#include "../Entities/Movement.h"
class ActiveState {

    public:

        //player instance
        Entity *player;
        lua_State *L;
        std::stack<Zone*> zones;
        ActiveState();
        Movement *movementComp;

        Blood *resources;

        float getPlayerX();
        float getPlayerY();

        int getIntField(lua_State *L, const char* key);
        std::string getStringField(lua_State *L, const char* key);

        sf::View *view;
        sf::View *resource_view;


        void update(sf::Time dt);
        void render(sf::RenderWindow *win);

};

#endif