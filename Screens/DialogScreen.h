#ifndef DIALOGSCREEN_H
#define DIALOGSCREEN_H

#include "BaseScreen.h"


class DialogScreen : public BaseScreen{

    public:
        sf::View *view;
        
        DialogScreen(TextureManager *tm, TextManager *ttm, sf::View *view) : BaseScreen(tm, ttm, view){
            init(tm, ttm);
        };
        void update(TextureManager *tm);

        void init(TextureManager *tm, TextManager *ttm);

};

#endif