#ifndef DIALOGSCREEN_H
#define DIALOGSCREEN_H

#include "BaseScreen.h"


class DialogScreen : public BaseScreen{

    public:    
        DialogScreen(TextureManager *tm, TextManager *ttm, sf::View *view) : BaseScreen(tm, ttm, view){
            init(tm, ttm);
        };
        void update(TextureManager *tm);

        void init(TextureManager *tm, TextManager *ttm);


        int lastViewX;
        int lastViewY;
        int viewSizeX;
        int viewSizeY;

        float incrementSize = 1 ;
    
    


};

#endif