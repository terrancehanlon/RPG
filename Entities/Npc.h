#ifndef NPC_H
#define NPC_H

#pragma

#include "../Lib/TextureManager.h"
#include <string>

class Npc {

    protected:
        AnimatedSprite ani;
        Animation anim;

    public:
        Npc();
        void init(TextureManager *tm);
        
        std::string name;

        void render(sf::RenderWindow *window, TextureManager *tm);
        void update(sf::Time dt, TextureManager *tm);
        

};


#endif