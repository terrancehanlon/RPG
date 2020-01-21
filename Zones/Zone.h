#ifndef ZONE_H
#define ZONE_H

// #include "../Lib/Imports.h"
#include "../Entities/Computer.h"

class Zone {

    private:
        sf::Texture texture;
        sf::Sprite sprite;
        Computer *comp;
        lua_State *L;

    public:
        Zone();
        ~Zone();
        int getIntField(lua_State *L, const char* key);
        void update(sf::Time deltaTime, float x, float y);
        void draw(sf::RenderWindow *window);

        //checks if player is walking over restricted coords given from lua file
        bool checkPlayerConstraint(float x, float y);

};

#endif