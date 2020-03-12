#ifndef ZONE_H
#define ZONE_H

#include "../Entities/Computer.h"

class Zone {

    private:
        sf::Texture texture;
        sf::Sprite sprite;
        Computer *comp;
        lua_State *L;
        bool onScreen = false;

    public:
        Zone();
        ~Zone();
        int getIntField(lua_State *L, const char* key);
        void update(sf::Time deltaTime, float x, float y, sf::RenderWindow* win);
        void draw(sf::RenderWindow *window);

        //checks if player is walking over restricted coords given from lua file
        bool checkPlayerConstraint(float x, float y);
};

#endif