#include "ZoneBase.h"
#include <cmath>

ZoneBase::ZoneBase(){}
ZoneBase::~ZoneBase(){}

void ZoneBase::update(sf::Time dt, float x, float y){
    
    //update background
    // backgroundSprite.update(dt);

    //update interactable objects

    //update obstacles that are not interactable
    for(auto o : obstacles){
        o->update(dt);
    }
}

void ZoneBase::draw(sf::RenderWindow *window){

    //draw background
    window->draw(backgroundSprite);

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

bool ZoneBase::checkObstacleCollisin(AnimatedSprite* ani){
    //check for water and bridge obstacle
    bool onBridge = false;
    bool result = false;
    for(auto o : obstacles){
        if(o->isHard && o->ani.getGlobalBounds().intersects(ani->getGlobalBounds())){
            if(o->name == "bridge"){
                printf("on bridge\n");
                onBridge = true;
            }
            if(o->name == "stream" && onBridge){
                return false;
            }
            
            if(!onBridge){
                return true;
            }
            
        }    
    }

    return false;
}

void ZoneBase::obstaclesInView(AnimatedSprite *ani, float size, TextureManager *tm){
    for(auto o : obstacles){
            // o->show();
        // if(o->ani.getGlobalBounds().intersects(ani->getGlobalBounds())){

        // }
        if(std::abs( o->ani.getPosition().x - ani->getPosition().x) < (size + 15 ) ){
            if(std::abs(o->ani.getPosition().y - ani->getPosition().y) < (size + 15) ){
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