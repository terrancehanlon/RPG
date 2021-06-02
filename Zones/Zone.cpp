#include "Zone.h"
#include <string>
#include <iostream>

Zone::Zone(){
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
}


Zone::~Zone(){
    // delete &this->sprite;
    // delete &this->texture;
}

std::string Zone::getStringField(lua_State *L, const char* key){
    lua_pushstring(L, key);
    lua_gettable(L, -2);  // get table[key]
    const char * s = lua_tostring(L, -1);
    std::string str(s);
    lua_pop(L, 1);  // remove number from stack
    return s;
}

int Zone::getIntField(lua_State *L, const char* key){
    lua_pushstring(L, key);
    lua_gettable(L, -2);  // get table[key]

    int result = (int)lua_tonumber(L, -1);
    lua_pop(L, 1);  // remove number from stack
    return result;
}


bool Zone::checkPlayerConstraint(float x, float y){
    return false;
}

// bool Zone::checkObstacles(AnimatedSprite* ani){
//     // lua_getglobal(L, "trees");
//     int counter = 0; 
//     // for(int i = 0; i < coords.size(); i++){
//     //     for(int i = 0; i < coords.at(i).size(); i++){
            
//     //     }
//     // }
//     return true;
// }

bool Zone::renderObjectFirst(float playerX, float playerY){
    bool result = false;
    if(playerX > 60)
        if(playerX < 120)
            if(playerY > 525)
                result = true;
    
    if(playerX > 156)
        if(playerX < 203)
            if(playerY > 532)
                result = true;
    
    return result;
}