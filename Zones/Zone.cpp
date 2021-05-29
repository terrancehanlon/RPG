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

    std::vector<std::string> x;
    int len = getIntField(L, "constraints");
    
    for(int i = 1; i <= len; i++){
        std::string s = "constraint" + std::to_string(i);
        std::cout << s << std::endl;
        printf("%s\n", s.c_str());
        x.push_back(getStringField(L,s.c_str()));
    }

    for(int i = 0; i < x.size(); i++){
        Constraint *constraint = new Constraint();
        int pos;
        std::string statement = "";
        while( (pos = x.at(i).find(",")) != std::string::npos){
            std::string rawConstraint = x.at(i).substr(0,pos);
            // std::cout << rawConstraint << std::endl;
            if(rawConstraint.substr(0,1) == "9"){
                if(rawConstraint.substr(1,1) == "X"){
                    statement += "X > ";
                }
                else if(rawConstraint.substr(1,1) == "Y"){
                    statement += "Y > ";
                }
            }
            else if(rawConstraint.substr(0,1) == "7"){
                if(rawConstraint.substr(1,1) == "X"){
                    statement += "X < ";
                }
                else if(rawConstraint.substr(1,1) == "Y"){
                    statement += "Y < ";
                }
            }

            statement += rawConstraint.substr(2, rawConstraint.length() - 2);
            x.at(i).erase(0, pos + 1);
            if(x.at(i).length() > 0){
               statement += " && ";
            } 
        }
        std::cout << statement << std::endl;
        constraint->setConstraintString(statement);
        constraints.push_back(constraint);
    }

    // while((size_t pos = ))
    // //when counter is greater than three it means reset
    // int counter = 0;
    // Constraint 
    // for(int i = 0; i < len; i++){
    //     std::vector<std::string> rawConstraints;
    //     std::string statement = "";
    //     rawConstraints.push_back(x.at(i));
    //     if(x.at(i).substr(0,1) == "9"){
    //         if(x.at(i).substr(1,1) == "X"){
    //             statement += "X >= ";
    //         }
    //         else if(x.at(i).substr(1,1) == "Y"){
    //             statement += "Y >= ";
    //         }
    //     }
    //     else if(x.at(i).substr(0,1) == "7"){
    //         if(x.at(i).substr(1,1) == "X"){
    //             statement += "X <= ";
    //         }
    //         else if(x.at(i).substr(1,1) == "Y"){
    //             statement += "Y <= ";
    //         }
    //     }
    //     statement += x.at(i).substr(2, x.at(i).length() - 2);
        
    //     std::cout << "statement: " <<  statement << std::endl;
        //equality prefix (< > <= >=)
        // bool eq = "9" == s.substr(0,1);

        // Constraint* constraint = new Constraint();
        // for(int j = (i+1); j < (i+4); j++){
            
        // }

        // std::cout << x<< std::endl;
        // Constraint* _c = new Constraint()
        // std::cout << x.at(i) << std::endl;
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

bool Zone::renderObjectFirst(float playerX, float playerY){
    // for(int i = 0; i < constraints.size(); i++){

    // }

    bool result = false;

    if(playerX > 60)
        if(playerX < 120)
            if(playerY > 525)
                result = true;
    
    return result;
}