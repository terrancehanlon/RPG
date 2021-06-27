#ifndef SCREENITEM_H
#define SCREENITEM_H


#include "BaseScreen.h"
#include <string>

class ScreenItem {


    public:
        ScreenItem(std::string key, BaseScreen *screen);
        ScreenItem();
        std::string key;
        BaseScreen *screen;
        
        bool isVisible = true;
        bool toMake = false; //flag is set to true when a screen needs to be created


};

#endif