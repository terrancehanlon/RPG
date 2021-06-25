#include "ScreenManager.h"
#include <iostream>
#include <iterator>


ScreenManager::ScreenManager(TextureManager* tm, TextManager *ttm){
    this->tm = tm;
    this->ttm = ttm;
    printf("creating screenamanger\n");
}

void ScreenManager::render(sf::RenderWindow *window){
    // std::cout << activeScreens.size() << std::endl;
    for(auto& s : activeScreens){
        s->screen->render(window);
    }
};

void ScreenManager::update(TextureManager *tm){
    for(auto& s : activeScreens){
        s->screen->update(tm);
    }
};

void ScreenManager::addScreen(BaseScreen *screen){
    if(activeScreens_map.find(screen->key) != activeScreens_map.end()){
    }else{
        ScreenItem *screenItem = new ScreenItem();
        screenItem->key = screen->key;
        screenItem->screen = screen;
        // struct screenItem st = {screen.key, screen};
        activeScreens.push_back(screenItem);
        // activeScreens_map[screen.key] = 1;
    }
};

void ScreenManager::createScreen(std::string key){
    if(key == "interaction screen"){
        InteractionScreen *sc = new InteractionScreen(this->tm, this->ttm);
    }
}

void ScreenManager::removeScreen(std::string key){
    activeScreens.erase(std::remove_if(std::begin(activeScreens), std::end(activeScreens), [key](ScreenItem* const& s){
        return s->key == key;
    }), std::end(activeScreens));

    activeScreens_map.erase(key);
}

void ScreenManager::getSize(){
    std::cout << "activeScreens size: " << activeScreens.size() << std::endl;
}