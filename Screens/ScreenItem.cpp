#include "ScreenItem.h"

ScreenItem::ScreenItem(std::string key, BaseScreen *screen){
    this->key = key;
    this->screen = screen;
}

ScreenItem::ScreenItem(){};