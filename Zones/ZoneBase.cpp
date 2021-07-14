#include "ZoneBase.h"
#include <iostream>
#include <cmath>

ZoneBase::ZoneBase(TextureManager *tm, TextManager* ttm, ScreenManager *sm, sf::View *view){
    this->tm = tm;
    npc.init(tm);
    this->sm = sm;
    this->ttm = ttm;
    this->view = view;
}
ZoneBase::~ZoneBase(){}

void ZoneBase::update(sf::Time dt, float x, float y){
    for(auto o : obstacles){
        o->update(dt);
    }
    npc.update(dt, this->tm);
}

void ZoneBase::draw(sf::RenderWindow *window){
    window->draw(backgroundSprite);
    npc.render(window, this->tm);
}

void ZoneBase::drawObstacles(AnimatedSprite *ani, sf::RenderWindow *window, TextureManager *tm){
    obstaclesInView(ani, 5, tm);
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
            setColor = true;
        }
    }

    //collision happened
    if(setColor){
        npc.ani.setColor(sf::Color::Red);
        if(!tm->sw.diaglogActive){
            InteractionScreen *is = new InteractionScreen(this->tm, this->ttm, this->view, this->sm);
            // is->sm = this->sm;
            is->setPosition(npc.ani.getPosition().x - 8, npc.ani.getPosition().y - 3);
            sm->addScreen(is);    
        }else{
            DialogScreen *ds = new DialogScreen(this->tm, this->ttm, this->view);
        }
        return true;
    }else{
        npc.ani.setColor(sf::Color::White);
        sm->removeScreen("interaction-screen");
        tm->sw.diaglogActive = false;
        return false;
    }
}

bool ZoneBase::checkObstacleCollisin(AnimatedSprite* ani){
    bool onBridge = false;
    bool result = false;
    for(auto o : obstacles){
        if(o->isHard && o->ani.getGlobalBounds().intersects(ani->getGlobalBounds())){
            if(!o->isHard){
                return false;
            }
            if(o->name == "bridge"){
                onBridge = true;
                result = false;
            }else{
                result = true;
            }
        }
    }
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
}