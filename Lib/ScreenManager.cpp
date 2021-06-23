#include "ScreenManager.h"
#include <iostream>
#include <iterator>


ScreenManager::ScreenManager(TextureManager* tm, TextManager *ttm){
    this->tm = tm;
    this->ttm = ttm;
    printf("creating screenamanger\n");
    this->tm->getSize();
}

void ScreenManager::render(sf::RenderWindow *window){
    // std::cout << activeScreens.size() << std::endl;
    for(auto& s : activeScreens){
        s.screen.render(window);
    }
};

void ScreenManager::update(sf::Time dt){
    for(auto& s : activeScreens){
        s.screen.update(dt);
    }
};

void ScreenManager::addScreen(BaseScreen screen){
    std::cout << "Adding screen" << std::endl;
    struct screenItem st = {screen.key, screen};
    // if(screen.key.empty()){
    //     st.key = "key";
    // }else{
    //     st.key = screen.key;
    // }
    // st.screen = screen;
    activeScreens.push_back(st);
};

void ScreenManager::createScreen(std::string key){
    if(key == "interaction screen"){
        InteractionScreen *sc = new InteractionScreen(this->tm, this->ttm);
    }
}

void ScreenManager::removeScreen(std::string key){
    activeScreens.erase(std::remove_if(std::begin(activeScreens), std::end(activeScreens), [key](screenItem const& s){
        return s.key == key;
    }), std::end(activeScreens));
}