#include "ActiveState.h"
#include <iostream>

ActiveState::ActiveState(){
    printf("Creating active state\n");
    this->zones.push(new Zone());
    this->player = new Entity();
    this->resources = new Blood();
    this->view = new sf::View(sf::Vector2f(1024.0f, 1024.0f), sf::Vector2f(124.0f, 124.0f));
    this->movementComp = new Movement(0.055f);
    this->creatorComp = new Creator();

    this->L = luaL_newstate();
    luaL_loadfile(L, "Zones/constraints/zone1.lua");
    lua_pcall(L, 0, 0, 0);
    lua_getglobal(L, "zone1");
 
    printf("Lua loading\n");
    int width = getIntField(L, "startX");
    int height = getIntField(L, "startY");
    
    this->player->ani.setPosition(width, height);
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
    if(this->zones.top()->checkPlayerConstraint(getPlayerX(), getPlayerY())){
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
    if(this->player->ani.getPosition().x > 60 && this->player->ani.getPosition().x < 120 && this->player->ani.getPosition().y > 525){
        // if(this->player->ani.getPosition().y > 525 && this->player->ani.getPosition().y < 530){
            // printf("1\n");
            this->zones.top()->drawObstacles(win);
            this->player->render(win);
        // }
    }
    else{
        // printf("2\n");
        this->player->render(win);
        this->zones.top()->drawObstacles(win);
    }
    this->resources->render(win);
    // sf::Text text;
    // sf::Font font;
    // font.loadFromFile("Assets/fonts/OpenSans-Bold.ttf");
    // text.setFont(font);
    // text.setCharacterSize(24);
    // text.setString("Hover");
    // text.setColor(sf::Color::White);
    // text.setPosition(250, 250);
    // win->draw(text);          
};

