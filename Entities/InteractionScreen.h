#ifndef INTERACTIONSCREEN_H
#define INTERACTIONSCREEN_H

#include "BaseScreen.h"

class InteractionScreen : public BaseScreen {

    public:
        InteractionScreen(TextureManager *tm, TextManager *ttm) : BaseScreen(tm, ttm){
            init("interaction-screen", tm, ttm);
        }

        void update(TextureManager *tm);

};

#endif