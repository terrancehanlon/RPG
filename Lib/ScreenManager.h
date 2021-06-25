#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H


// #include "../Entities/BaseScreen.h"
#include "../Entities/InteractionScreen.h"
// #include "./TextureManager.h"
// #include "./TextManager.h"
#include <string>
#include <vector>

#include<unordered_map>
#include<map>
#include "ScreenItem.h"

class ScreenManager {

    protected:
        TextureManager *tm;
        TextManager *ttm;
        std::vector<ScreenItem*> activeScreens;
        std::unordered_map<std::string, int> activeScreens_map;


    public:
        ScreenManager(TextureManager* tm, TextManager *ttm);
        void render(sf::RenderWindow *window);
        void update(TextureManager *tm);

        void addScreen(BaseScreen *screen);

        void createScreen(std::string key);

        void removeScreen(std::string key);

        void getSize();
        
};

#endif