#ifndef INTERACTIONSCREEN_H
#define INTERACTIONSCREEN_H

// #include "BaseScreen.h"
#include "../Lib/ScreenManager.h"
class InteractionScreen : public BaseScreen {

    public:
        InteractionScreen(TextureManager *tm, TextManager *ttm, sf::View *view, ScreenManager *sm) : BaseScreen(tm, ttm, view){
            init(tm, ttm);
            this->sm = sm;
        }
        void update(TextureManager *tm);
        void init(TextureManager *tm, TextManager *ttm);
        ScreenManager *sm;
};

#endif