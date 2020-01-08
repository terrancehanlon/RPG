#ifndef GAME_H
#define GAME_H


#include "States/ActiveState.h"


class Game {

    public:

        sf::RenderWindow *window;
        std::stack<State*> states;

        Game();
        ~Game();
        
        void init();

        void update();
        void render();

        void run();




};

#endif