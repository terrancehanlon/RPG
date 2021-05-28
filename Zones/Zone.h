#ifndef ZONE_H
#define ZONE_H

#include "../Entities/Computer.h"
#include "../Entities/Obstacle.h"
#include <vector>
#include <string>

class Zone {

    private:
        sf::Texture texture;
        sf::Sprite sprite;
        Computer *comp;
        BloodCase *bloodCase;
        HumanPod *humanpod;
        lua_State *L;
        bool onScreen = false;
        std::vector<Obstacle*> obstacles;
        std::vector<std::vector<std::string>> coords;


    public:
        bool coolDown = false;
        Zone();
        ~Zone();
        int getIntField(lua_State *L, const char* key);
        std::string getStringField(lua_State *L, const char* key);
        void update(sf::Time deltaTime, float x, float y);
        void draw(sf::RenderWindow *window);
        void drawObstacles(sf::RenderWindow *window);
        bool checkObstacles(AnimatedSprite *ani);

        //checks if player is walking over restricted coords given from lua file
        bool checkPlayerConstraint(float x, float y);
};

#endif