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
        InteractionScreen *is = new InteractionScreen(this->tm, this->ttm);
        is->setPosition(npc.ani.getPosition().x - 8, npc.ani.getPosition().y - 3);
        sm->addScreen(is);
        return true;
    }else{
        npc.ani.setColor(sf::Color::White);
        sm->removeScreen("interaction-screen");
        return false;
    }
}

bool ZoneBase::checkObstacleCollisin(AnimatedSprite* ani){
    //check for water and bridge obstacle
    bool onBridge = false;
    bool result = false;
    for(auto o : obstacles){
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
    }
    // onBridge = false;
    return result;
}

void ZoneBase::obstaclesInView(AnimatedSprite *ani, float size, TextureManager *tm){
    for(auto o : obstacles){
        
        if(std::abs( o->ani.getPosition().x - ani->getPosition().x) < (size + 125 ) ){
            if(std::abs(o->ani.getPosition().y - ani->getPosition().y) < (size + 125) ){
                o->show(tm);
                o->visible = true;
            }
        }else{
            o->visible = false;
        }
    }

    /* 

        abs( (obstacle.x + obstacle.size.x) - (ani.getPosition.x + size)) 
    
    */
}