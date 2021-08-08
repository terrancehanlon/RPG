#ifndef ZONE_H
#define ZONE_H

// #include "../Entities/Computer.h"
// #include "../Entities/Obstacle.h"
// #include "./constraints/Constraint.h"
#include "ZoneBase.h"
#include <vector>
#include <string>
#include "../Entities/NPC/StaticNpc.h"

class Zone : public ZoneBase {

    private:
        bool onScreen = false;

    public:
        bool coolDown = false;
        Zone(TextureManager *tm, TextManager *ttm, ScreenManager *sm, sf::View *view) : ZoneBase(tm, ttm, sm, view){
                this->backgroundTexture.loadFromFile("Assets/16x16p2.png");
    
                this->backgroundSprite.setTexture(this->backgroundTexture);  
                Obstacle *o = new Obstacle;
                o->tree();
                obstacles.push_back(o);

                Obstacle *o1 = new Obstacle;
                o1->tree();
                o1->ani.setPosition(sf::Vector2f(350, 150));
                obstacles.push_back(o1);

                Obstacle *o2 = new Obstacle;
                o2->stream();
                obstacles.push_back(o2);

                Obstacle *o3 = new Obstacle;
                o3->bridge();
                obstacles.push_back(o3);

                StaticNpc npc1;


        }
        ~Zone();
        int getIntField(lua_State *L, const char* key);
        std::string getStringField(lua_State *L, const char* key);
        virtual bool renderObjectFirst(float playerX, float playerY);

        //checks if player is walking over restricted coords given from lua file
        virtual bool checkPlayerConstraint(float x, float y);

};

#endif