#include "Zone.h"
#include <string>
#include <iostream>

Zone::Zone(){
    this->texture.loadFromFile("Assets/rpg-zone1.png");
    this->sprite.setTexture(this->texture);  
    this->comp = new Computer();
    this->comp->ani.setPosition(250, 250);
    this->bloodCase = new BloodCase();
    this->bloodCase->ani.setPosition(260, 350);
    this->humanpod = new HumanPod();
    this->humanpod->ani.setPosition(260, 450);
    this->L = luaL_newstate();
    luaL_loadfile(L, "Zones/constraints/zone1.lua");
    lua_pcall(L, 0, 0, 0);
    lua_getglobal(L, "zone1");
 
    int width = getIntField(L, "startX");
    int height = getIntField(L, "startY");
    printf("%d\n", height);

    // lua_State* _L = luaL_newstate();
    // lua_pcall(_L, 0, 0, 0);
    // lua_getglobal(_L, "trees");
    std::vector<int> x;

    // lua_pushnil(_L);
    // int index = lua_gettop(_L);
    int len = getIntField(L, "size");
    printf("%d\n", len);
    // int c = getIntField(cleaL, "coord1")
    
    // for(int i = 1; i <= len; i++){
    //     std::string s = "cord" + std::to_string(i);
    //     std::cout << s << std::endl;
    //     printf("%s\n", s.c_str());
    //     x.push_back(getIntField(L,s.c_str()));
    // }

    std::string cd = getStringField(L, "cord1");
    std::cout << cd << std::endl;
    

    // for(int i = 0; i < len; i++){
    //     std::cout << x.at(i) << std::endl;
    // }

    // int counter = 1;
    // int idx = 0;
    // std::vector<int> _coords;
    // for(int i = 0; i < len; i++){
    //     if(counter == 5){
    //         coords.push_back(_coords);
    //         counter = 1;
    //     }
    //     else{
    //         _coords.push_back(x.at(i));
    //     }
    // }

    
    Obstacle *o = new Obstacle;
    o->tree();
    obstacles.push_back(o);
    // std::string title = getStringField(L, "title");
}


Zone::~Zone(){
    delete &this->sprite;
    delete &this->texture;
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

void Zone::draw(sf::RenderWindow *window){
    if(this->onScreen){
        if(!coolDown){
            
        }
        // window->getDefaultView();
        // window->draw(comp->screen->ani);

        // this->comp->displayerscreen(window);
        // this->comp->draw(window, false);
        window->draw(this->sprite);

        this->bloodCase->render(window);
        this->humanpod->render(window);
    }else{
        this->comp->draw(window, false);
        this->bloodCase->render(window);
        this->humanpod->render(window);
        window->draw(this->sprite);
        // for(int i = 0; i < obstacles.size(); i++){
        //     obstacles.at(i)->render(window);
        // }
    }
}

bool Zone::checkPlayerConstraint(float x, float y){
    int waterRangeStartY = getIntField(this->L, "waterRangeStartY");
    int waterRangeEndY = getIntField(this->L, "waterRangeEndY");
    
    int waterRangeStartX = getIntField(this->L, "waterRangeStartX");
    int waterRangeEndX = getIntField(this->L, "waterRangeEndX");
    
    int bridgeRangeStartX = getIntField(this->L, "bridgeStartX");
    //int bridgeRangeEndX = getIntField(this-L, "bridgeEndX");

    int bridgeRangeStartY = getIntField(this->L, "bridgeStartY");
    int bridgeRangeEndY = getIntField(this->L, "bridgeEndY");

    bool result = false;

    //first constraint check
    //check if on bridge
    if (x > (bridgeRangeStartX - 5)){
        if(y < bridgeRangeEndY && y > bridgeRangeStartY){
            return false;
        }
    }

    //restrict player from going into water
    if( x > (waterRangeStartX - 5)&& (x < (waterRangeEndX) )){
        if(y < (waterRangeEndY) && y > (waterRangeStartY - 5)){
            result = true;
        }
    }


    return result;

}

void Zone::update(sf::Time deltaTime, float x, float y){
    if(this->comp->ani.getGlobalBounds().contains(sf::Vector2f(x,y))){
        // printf("Crossing over computer\n");
        this->onScreen = true;
        this->comp->update(deltaTime, false);
        this->bloodCase->update(deltaTime);
        this->humanpod->update(deltaTime);
        for(int i = 0; i < this->obstacles.size(); i++){
           obstacles.at(i)->update(deltaTime);
        }
        // this->comp->update(deltaTime, true);
    }
    else{
        this->onScreen = false;
        this->comp->update(deltaTime, false);
        this->bloodCase->update(deltaTime);
        this->humanpod->update(deltaTime);
    }
}

void Zone::drawObstacles(sf::RenderWindow* window){
        for(int i = 0; i < obstacles.size(); i++){
            obstacles.at(i)->render(window);
        }
}

bool Zone::checkObstacles(AnimatedSprite* ani){
    // lua_getglobal(L, "trees");
    int counter = 0; 
    // for(int i = 0; i < coords.size(); i++){
    //     for(int i = 0; i < coords.at(i).size(); i++){
            
    //     }
    // }
    return true;
}