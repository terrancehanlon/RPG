#ifndef ACTIVE_STATE
#define ACTIVE_STATE

// #include "State.h"
#include "../Entities/Entity.h"
#include "BaseState.h"
#include "../Lib/ScreenManager.h"
#include <string>
#include <stack>
#include "../Zones/Zone.h"
#include "../Entities/Movement.h"
#include "../Entities/Creator.h"
// #include "../"
class ActiveState : public BaseState{

    public:

        //player instance
        Entity *player;
        lua_State *L;
        std::stack<ZoneBase*> zones;
        ActiveState(TextureManager *tm);
        TextureManager *tm;
        ScreenManager *sm;
        TextManager *ttm;
        Movement *movementComp;
        Creator *creatorComp;

        Storage inventory;


        Blood *resources;
        // TextureManager tm;

        float VIEW_SIZE = 124.0f;

        // TextureManager textureManager;

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