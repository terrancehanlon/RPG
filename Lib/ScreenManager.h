#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H


// #include "../Entities/BaseScreen.h"
#include "../Entities/InteractionScreen.h"
// #include "./TextureManager.h"
// #include "./TextManager.h"
#include <vector>


class ScreenManager {

    protected:
        TextureManager *tm;
        TextManager *ttm;
        std::vector<BaseScreen> activeScreens;


    public:
        ScreenManager(TextureManager* tm, TextManager *ttm);
        void render(sf::RenderWindow *window);
        void update(sf::Time dt);

        void addScreen(BaseScreen screen);

        void createScreen(std::string key);
        
};

#endif