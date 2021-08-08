#ifndef NPC_H
#define NPC_H

#pragma

#include "../../Lib/TextureManager.h"
#include <string>

class Npc {

    protected:
        Animation anim;

    public:
        AnimatedSprite ani;
        Npc();
        virtual void init(TextureManager *tm);
        
        std::string name;

        void render(sf::RenderWindow *window, TextureManager *tm);
        void update(sf::Time dt, TextureManager *tm);

        bool hit = false;
        

};


#endif