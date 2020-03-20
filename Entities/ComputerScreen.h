#ifndef COMPUTERSCREEN_H
#define COMPUTERSCREEN_H

#include "./Movement.h"

//Should be the general container component of the computer screen

class ComputerScreen {

    private:

    public:
        AnimatedSprite ani;
        Animation anim;
        sf::Texture txt;
        ComputerScreen();
        ~ComputerScreen();

        void initgraphics();

        void showHelp();

        void update(sf::Time dt);
        void render(sf::RenderWindow* window);

};

#endif