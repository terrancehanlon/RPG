#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H


// #include "../Entities/BaseScreen.h"
#include "../Entities/InteractionScreen.h"
// #include "./TextureManager.h"
// #include "./TextManager.h"
#include <string>
#include <vector>

struct screenItem
{
    std::string key;
    BaseScreen screen;
};


class ScreenManager {

    protected:
        TextureManager *tm;
        TextManager *ttm;
        std::vector<screenItem> activeScreens;


    public:
        ScreenManager(TextureManager* tm, TextManager *ttm);
        void render(sf::RenderWindow *window);
        void update(sf::Time dt);

        void addScreen(BaseScreen screen);

        void createScreen(std::string key);

        void removeScreen(std::string key);
        
};

#endif