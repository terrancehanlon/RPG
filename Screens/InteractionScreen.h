#ifndef INTERACTIONSCREEN_H
#define INTERACTIONSCREEN_H

#include "BaseScreen.h"
#include "../Lib/ScreenManager.h"
class InteractionScreen : public BaseScreen {

    public:
        InteractionScreen(TextureManager *tm, TextManager *ttm) : BaseScreen(tm, ttm){
            init(tm, ttm);
        }
        void update(TextureManager *tm);
        void init(TextureManager *tm, TextManager *ttm);

};

#endif