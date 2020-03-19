#ifndef GAME_H
#define GAME_H


#include "States/ActiveState.h"
#include "Lib/Imports.h"


class Game {

    public:

        sf::RenderWindow *window;
        std::stack<ActiveState*> states;

        sf::View *view;

        Game();
        ~Game();
        
        void init();

        void update();
        void render();

        void run();




};

#endif