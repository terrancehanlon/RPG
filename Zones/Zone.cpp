#include "Zone.h"

Zone::Zone(){
    this->texture.loadFromFile("Assets/rpg-zone1.png");
    this->sprite.setTexture(this->texture);  
    this->comp = new Computer();
    this->comp->ani.setPosition(250, 250);
    this->L = luaL_newstate();
    luaL_loadfile(L, "Zones/constraints/zone1.lua");
    lua_pcall(L, 0, 0, 0);
    lua_getglobal(L, "zone1");
 
    // int width = getIntField(L, "startX");
    // int height = getIntField(L, "startY");
    // std::string title = getStringField(L, "title");
}


Zone::~Zone(){
    delete &this->sprite;
    delete &this->texture;
}

int Zone::getIntField(lua_State *L, const char* key){
    lua_pushstring(L, key);
    lua_gettable(L, -2);  // get table[key]
 
    int result = (int)lua_tonumber(L, -1);
    lua_pop(L, 1);  // remove number from stack
    return result;
}

void Zone::draw(sf::RenderWindow *window){
    window->draw(this->sprite);
    this->comp->draw(window);
}

bool Zone::checkPlayerConstraint(float x, float y){
    int waterRangeStartY = getIntField(this->L, "waterRangeStartY");
    int waterRangeEndY = getIntField(this->L, "waterRangeEndY");
    int waterRangeStartX = getIntField(this->L, "waterRangeStartX");
    int waterRangeEndX = getIntField(this->L, "waterRangeEndX");


    bool result = false;

    //first constraint check
    //restrict player from going into water
    if( (x < (waterRangeEndX) ) && x > (waterRangeStartX - 5)){
        if(y < (waterRangeEndY) && y > (waterRangeStartY - 5)){
            result = true;
        }
    }


    return result;

}

void Zone::update(sf::Time deltaTime, float x, float y){
    this->comp->update(deltaTime);
    // if( (window->getSize().y) < y){
    //     // printf("Player below screen\n");
    //     //this->sprite.setPosition(this->sprite.getPosition().x, this->sprite.getPosition().y - 1);
    //     // this->
    // }
    // sf::Style::Fullscreen-
}