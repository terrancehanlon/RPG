#include "ActiveState.h"
#include <iostream>

ActiveState::ActiveState(){
    printf("Creating active state\n");
    printf("Adding instances\n");
    
    tm.addTexture("pixel", "/home/terrance/Desktop/games/RPG/Assets/pixel.png");
    tm.addTexture("new-walk", "Assets/new-walk.png");
    tm.addTexture("npc1", "Assets/base-walk.png");
    tm.addTexture("tree", "Assets/obst-tree.png");
    tm.addTexture("stream", "Assets/water.png");
    tm.addTexture("bridge", "Assets/bridge.png");
    tm.addTexture("blood-levels", "Assets/blood-levels.png");
    // TextureManager::getInstance().addTexture("pixel", "/home/terrance/Desktop/games/RPG/Assets/pixel.png");
    // TextureManager::getInstance().addTexture("tree", "Assets/obst-tree.png");
    // TextureManager::getInstance().addTexture("stream", "Assets/water.png");
    // TextureManager::getInstance().addTexture("bridge", "Assets/bridge.png");

    printf("adding zones\n");
    this->zones.push(new Zone(&tm));
    this->player = new Entity(&tm);
    this->resources = new Blood(&tm);
    this->view = new sf::View(sf::Vector2f(1024.0f, 1024.0f), sf::Vector2f(VIEW_SIZE, VIEW_SIZE)); ///124 x124
    this->movementComp = new Movement(0.055f);
    this->creatorComp = new Creator();

    this->L = luaL_newstate();
    luaL_loadfile(L, "Zones/constraints/zone1.lua");
    lua_pcall(L, 0, 0, 0);
    lua_getglobal(L, "zone1");
 
    printf("Lua loading\n");
    int width = getIntField(L, "startX");
    int height = getIntField(L, "startY");
    
    this->player->ani.setPosition(150, 150);
    this->view->setCenter(getPlayerX(), getPlayerY());
    this->resources->ani.setPosition(view->getCenter().x - 60, getPlayerY() - 60);
    
    lua_close(L);
};

float ActiveState::getPlayerX(){
    return this->player->ani.getPosition().x;
}

float ActiveState::getPlayerY(){
    return this->player->ani.getPosition().y;
}

int ActiveState::getIntField(lua_State *L, const char* key){
    lua_pushstring(L, key);
    lua_gettable(L, -2);  // get table[key]
 
    int result = (int)lua_tonumber(L, -1);
    lua_pop(L, 1);  // remove number from stack
    return result;
}

std::string ActiveState::getStringField(lua_State* L, const char* key)
{
    lua_pushstring(L, key);
    lua_gettable(L, -2);  // get table[key]
 
    std::string result = lua_tostring(L, -1);
    lua_pop(L, 1);  // remove string from stack
    return result;
}

void ActiveState::update(sf::Time dt){
    if(movementComp->create){
        printf("Adding fp \n");
        this->creatorComp->create("hp");
        this->movementComp->create = false;
    }
    if(this->zones.top()->checkObstacleCollisin(&this->player->ani)){
        // printf("trigger the back peddle\n");
        this->movementComp->backPeddle(&this->player->ani, &this->resources->ani, this->view);

    }else{
        this->movementComp->move(dt, &this->player->ani, &this->resources->ani, this->view);   
    }
    this->creatorComp->update(dt);
    this->zones.top()->update(dt, this->player->ani.getPosition().x, this->player->ani.getPosition().y);
    this->resources->update(dt);
    this->player->update(dt);

};
//change function names to match draw to render or render to draw
void ActiveState::render(sf::RenderWindow *win){
    win->setView(*this->view);
    //TODO rename draw to render
    this->zones.top()->draw(win);
    this->creatorComp->render(win);

    //rather than hard coded values place this into the lua file and read from there?
    // works good circles the tree
    // make a lua reader program?
    
    /* 
        If player should render first that means player is in front of object
        If object should render first it means player is behind the object (obstacle)
    */
   this->zones.top()->obstaclesInView(&this->player->ani, VIEW_SIZE, &this->tm);
    if(this->zones.top()->renderObjectFirst(this->player->ani.getPosition().x, this->player->ani.getPosition().y)){
        this->zones.top()->drawObstacles(&this->player->ani, win, &this->tm);
        this->player->render(win);
    }
    else{
        this->player->render(win);
        this->zones.top()->drawObstacles(&this->player->ani, win, &this->tm);
    }
    this->resources->render(win);       
};

