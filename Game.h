#ifndef GAME_H
#define GAME_H


#include "States/ActiveState.h"
#include "States/Menu.h"
// #include "Lib/Imports.h"
#include "Lib/TextureManager.h"
// #include "Lib/TextManager.h"


class Game {

    public:

        sf::RenderWindow *window;
        std::stack<BaseState*> states;
        TextureManager tm;
        TextManager ttm;
        sf::View *view;

        Game();
        ~Game();
        
        void init();

        void update();
        void render();

        void run();




};

#endif