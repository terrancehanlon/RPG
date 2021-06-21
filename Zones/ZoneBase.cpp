#include "ZoneBase.h"
#include <iostream>
#include <cmath>

ZoneBase::ZoneBase(TextureManager *tm, TextManager* ttm, ScreenManager *sm){
    this->tm = tm;
    npc.init(tm);
    this->sm = sm;
    this->ttm = ttm;
}
ZoneBase::~ZoneBase(){}

void ZoneBase::update(sf::Time dt, float x, float y){
    
    //update background
    // backgroundSprite.update(dt);

    //update interactable objects

    //update obstacles that are not interactable
    for(auto o : obstacles){
        o->update(dt);
    }
    npc.update(dt, this->tm);
}

void ZoneBase::draw(sf::RenderWindow *window){

    //draw background
    window->draw(backgroundSprite);
    // window->draw(npc);
    npc.render(window, this->tm);

    //draw interactable objects

    //draw obstacles
    // for(auto o : obstacles){
    //     o->render(window);
    // }
}

void ZoneBase::drawObstacles(AnimatedSprite *ani, sf::RenderWindow *window, TextureManager *tm){
    obstaclesInView(ani, 5, tm);
    //draw obstacles
    for(auto o : obstacles){
        if(o->visible){
            o->render(window);
        }
    }
}

void ZoneBase::drawScreens(sf::RenderWindow *window){
    this->sm->render(window);
}

bool ZoneBase::checkNPCCollision(AnimatedSprite* ani){
    float x = ani->getPosition().x;
    float y = ani->getPosition().y;
    
    bool setColor = false;
     if( std::abs(this->npc.ani.getPosition().x - x) < 15 ){
        if(std::abs(this->npc.ani.getPosition().y - y) < 15){
            // npc.ani.setColor(sf::Color::Red);
            setColor = true;
        }
    }

    if(setColor){
        npc.ani.setColor(sf::Color::Red);
        printf("before interaction screen init\n");
        this->tm->getSize();
        InteractionScreen *is = new InteractionScreen(this->tm, this->ttm);
        return true;
    }else{
        return false;
        npc.ani.setColor(sf::Color::White);
    }
}

bool ZoneBase::checkObstacleCollisin(AnimatedSprite* ani){
    //check for water and bridge obstacle
    bool onBridge = false;
    bool result = false;
    for(auto o : obstacles){
        // std::cout << o->name == "bridge" << std::endl;
        // if(onBridge){
        //     printf("on bridge\n");
        //     result = false; 
        //     // return false;
        // }
        if(o->isHard && o->ani.getGlobalBounds().intersects(ani->getGlobalBounds())){
            if(!o->isHard){
                return false;
            }
            // std::cout << "collision with " << o->name << std::endl;
            if(o->name == "bridge"){
                onBridge = true;
                result = false;
                // return false;
            }else{
                result = true;
            }
        }
            // if(o->name == "stream"){
            //     if(onBridge){
            //         return false;
            //     }
            // }[]
            // else{
            //     onBridge = false;
            //     return true;
            // }
            // onBridge = false;
            // return true;
            // return true;
            // else{
            //     onBridge = false;
            //     return true;
            // }
            // if(o->name == "stream" && onBridge){
            //     return false;
            // }
            
            // if(!onBridge){
            //     printf("returning true\n");
            //     return true;
            // }

            //not on bridge 
            // return true;
            
        // }
        // else{
        //     printf("no collisions\n");
        //     onBridge = false;
        // }    
    }
    // onBridge = false;
    return result;
}

void ZoneBase::obstaclesInView(AnimatedSprite *ani, float size, TextureManager *tm){
    for(auto o : obstacles){
            // o->show();
        // if(o->ani.getGlobalBounds().intersects(ani->getGlobalBounds())){

        // }
        
        if(std::abs( o->ani.getPosition().x - ani->getPosition().x) < (size + 125 ) ){
            if(std::abs(o->ani.getPosition().y - ani->getPosition().y) < (size + 125) ){
                o->show(tm);
                o->visible = true;
                // printf("showiing\n:");
            }
        }else{
            o->visible = false;
            // printf("unshowing\n");
            // o->unshow();
            // o->texture.clear()
        }
    }

    /* 

        abs( (obstacle.x + obstacle.size.x) - (ani.getPosition.x + size)) 
    
    */
}