#ifndef INTERACTIONSCREEN_H
#define INTERACTIONSCREEN_H

#include "BaseScreen.h"

class InteractionScreen : public BaseScreen {

    public:
        InteractionScreen(TextureManager *tm, TextManager *ttm) : BaseScreen(){
            init("interaction-screen", tm, ttm);
        }

};

#endif