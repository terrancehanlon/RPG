#ifndef COMPUTER_H
#define COMPUTER_H

#include "../Lib/Imports.h"

class Computer {
    
    public:

        AnimatedSprite ani;
        Animation anim;
        sf::Texture text;
        
        Computer();
        ~Computer();

        void initGraphics();

        void update(sf::Time dt);
        void draw(sf::RenderWindow *window);



};


#endif