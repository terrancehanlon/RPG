#ifndef MENU_H
#define MENU_H

#include "../Lib/TextureManager.h"
#include <vector>
#include "BaseState.h"
class Menu : public BaseState {

    protected:
        sf::Font font;
        sf::Sprite background;
        std::vector<sf::Text> texts;

    public:
        Menu(TextureManager *tm);
        
        void update(sf::Time dt);
        void render(sf::RenderWindow *window);


};




#endif