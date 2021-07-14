#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H


// #include "../Entities/BaseScreen.h"
// #include "../Screens/InteractionScreen.h"
// #include "./TextureManager.h"
// #include "./TextManager.h"
#include <string>
#include <vector>

#include<unordered_map>
#include<map>
#include "../Screens/ScreenItem.h"


class ScreenManager {

    protected:
        TextureManager *tm;
        TextManager *ttm;
        std::vector<ScreenItem*> activeScreens;
        std::unordered_map<std::string, int> activeScreens_map;
        sf::View *view;

    public:

        bool dialogScreenActive = false;

        ScreenManager(TextureManager* tm, TextManager *ttm, sf::View *view);
        void render(sf::RenderWindow *window);
        void update(TextureManager *tm);

        void addScreen(BaseScreen *screen);

        void createScreen(std::string key);

        void removeScreen(std::string key);

        void getSize();

        bool checkIfExists(std::string key);
        
};

#endif