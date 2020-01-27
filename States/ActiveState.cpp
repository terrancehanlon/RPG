#include "ActiveState.h"
#include <iostream>

ActiveState::ActiveState(sf::RenderWindow *window) : State(window){
    printf("Creating active state\n");
    this->zones.push(new Zone());
    this->player = new Entity();
    this->initState();
    this->view = new sf::View(sf::Vector2f(1024.0f, 1024.0f), sf::Vector2f(124.0f, 124.0f));
    this->movementComp = new Movement(0.055f);

    this->L = luaL_newstate();
    luaL_loadfile(L, "Zones/constraints/zone1.lua");
    lua_pcall(L, 0, 0, 0);
    lua_getglobal(L, "zone1");
 
    int width = getIntField(L, "startX");
    int height = getIntField(L, "startY");
    // std::string title = getStringField(L, "title");
    
    this->player->ani.setPosition(width, height);
    this->view->setCenter(getPlayerX(), getPlayerY());
    
    std::cout << "X = " << width << std::endl;
    std::cout << "Y = " << height << std::endl;
    // std::cout << "Title = " << title << std::endl;
 
    lua_close(L);
};

void ActiveState::initState(){
    printf("Initilaizing ActiveState\n");
    //draw state (zone)
    this->window->clear(sf::Color::Magenta);    
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
    if(this->zones.top()->checkPlayerConstraint(getPlayerX(), getPlayerY())){
        this->movementComp->backPeddle(&this->player->ani, this->view);

    }else{
        this->movementComp->move(dt, &this->player->ani, this->view);   
    }
    //zone.update(dt)
    this->zones.top()->update(dt, 0.0f, 0.0f);
    this->player->update(dt);
};

void ActiveState::render(){
    this->window->setView(*this->view); 
    this->zones.top()->draw(this->window);
    this->player->render(this->window);
};

