#include "ScreenManager.h"
#include <iostream>
#include <iterator>


ScreenManager::ScreenManager(TextureManager* tm, TextManager *ttm, sf::View *view){
    this->tm = tm;
    this->ttm = ttm;
    this->view = view;
}

void ScreenManager::render(sf::RenderWindow *window){
    for(auto& s : activeScreens){
        s->screen->printPosition();
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
        printf("screen already active\n");
    }else{
        ScreenItem *screenItem = new ScreenItem(screen->key, screen);
        activeScreens.push_back(screenItem);
        this->activeScreens_map.insert(std::make_pair<std::string,int>(std::move(screen->key), 1));
    }
};

void ScreenManager::createScreen(std::string key){
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

bool ScreenManager::checkIfExists(std::string key){
    for(auto& s : activeScreens){
        if(s->key == key) return true;
    }
    return false;
}