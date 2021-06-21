#include "ScreenManager.h"


ScreenManager::ScreenManager(TextureManager* tm, TextManager *ttm){
    this->tm = tm;
    this->ttm = ttm;
    printf("creating screenamanger\n");
    this->tm->getSize();
}

void ScreenManager::render(sf::RenderWindow *window){
    for(auto& s : activeScreens){
        s.render(window);
    }
};

void ScreenManager::update(sf::Time dt){
    for(auto& s : activeScreens){
        s.update(dt);
    }
};

void ScreenManager::addScreen(BaseScreen screen){
    activeScreens.push_back(screen);
};

void ScreenManager::createScreen(std::string key){
    if(key == "interaction screen"){
        InteractionScreen *sc = new InteractionScreen(this->tm, this->ttm);
    }
}