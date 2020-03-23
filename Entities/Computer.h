#ifndef COMPUTER_H
#define COMPUTER_H

#include "./ComputerScreen.h"
#include "./Rock.h"
class Computer : public Rock{
    
    public:

        AnimatedSprite ani;
        Animation anim;
        sf::Texture text;
        ComputerScreen* screen;
        
        
        Computer();
        ~Computer();

        void initGraphics();

        void update(sf::Time dt, bool onScreen);
        void draw(sf::RenderWindow *window, bool onScreen);

        void displayerscreen(sf::RenderWindow *window);





};


#endif