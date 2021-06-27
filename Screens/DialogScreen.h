#ifndef DIALOGSCREEN_H
#define DIALOGSCREEN_H

#include "BaseScreen.h"


class DialogScreen : public BaseScreen {

    public:
        DialogScreen(TextureManager *tm, TextManager *ttm) : BaseScreen(tm, ttm){
            init("dialog-screen", tm, ttm);
        }

        void update(TextureManager *tm);
    

};

#endif