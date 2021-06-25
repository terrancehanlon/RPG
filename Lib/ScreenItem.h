#ifndef SCREENITEM_H
#define SCREENITEM_H


#include "../Entities/BaseScreen.h"
#include <string>

class ScreenItem {


    public:
        ScreenItem(std::string key, BaseScreen *screen);
        ScreenItem();
        std::string key;
        BaseScreen *screen;


};

#endif