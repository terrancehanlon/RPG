#ifndef DIALOGSCREEN_H
#define DIALOGSCREEN_H

#include "BaseScreen.h"


class DialogScreen : public BaseScreen{

    public:
        sf::View *view;
        sf::Sprite sprite;

        DialogScreen(TextureManager *tm, TextManager *ttm, sf::View *view) : BaseScreen(tm, ttm, view){
            // printf("")
            this->sprite.setTexture(tm->getTexture("dialogBox"));
        };
        void update(TextureManager *tm);
        // void render(sf::RenderWindow *window);
    

};

#endif