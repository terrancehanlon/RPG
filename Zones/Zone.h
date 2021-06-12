#ifndef ZONE_H
#define ZONE_H

// #include "../Entities/Computer.h"
// #include "../Entities/Obstacle.h"
// #include "./constraints/Constraint.h"
#include "ZoneBase.h"
#include <vector>
#include <string>

class Zone : public ZoneBase {

    private:
        // sf::Texture texture;
        // sf::Sprite sprite;
        // Computer *comp;
        // BloodCase *bloodCase;
        // HumanPod *humanpod;
        // lua_State *L;
        bool onScreen = false;
        // std::vector<Obstacle*> obstacles;
        // std::vector<std::vector<std::string>> coords;
        // std::vector<Constraint*> constraints;


    public:
        bool coolDown = false;
        Zone(TextureManager *tm) : ZoneBase(tm){
                this->backgroundTexture.loadFromFile("Assets/16x16p2.png");
    this->backgroundSprite.setTexture(this->backgroundTexture);  

    Obstacle *o = new Obstacle;
    o->tree();
    obstacles.push_back(o);

    Obstacle *o1 = new Obstacle;
    o1->tree();
    o1->ani.setPosition(sf::Vector2f(350, 150));
    obstacles.push_back(o1);

    //ani.setPosition(sf::Vector2f(95, 0));
    Obstacle *o2 = new Obstacle;
    o2->stream();
    obstacles.push_back(o2);

    Obstacle *o3 = new Obstacle;
    o3->bridge();
    obstacles.push_back(o3);
        }
        ~Zone();
        int getIntField(lua_State *L, const char* key);
        std::string getStringField(lua_State *L, const char* key);
        // void update(sf::Time deltaTime, float x, float y);
        // void draw(sf::RenderWindow *window);
        // void drawObstacles(sf::RenderWindow *window);
        // bool checkObstacles(AnimatedSprite *ani);
        // virtual bool renderPlayerFirst(float playerX, float playerY);
        virtual bool renderObjectFirst(float playerX, float playerY);

        //checks if player is walking over restricted coords given from lua file
        virtual bool checkPlayerConstraint(float x, float y);

};

#endif