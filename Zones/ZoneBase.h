#ifndef ZONEBASE_H
#define ZONEBASE_H

#pragma once

// #include "../Lib/Imports.h"
// #include "../Lib/TextureManager.h"
#include "../Lib/ScreenManager.h"
#include "../Screens/DialogScreen.h"
// #include "../Lib/TextManager.h"
#include "../Entities/Obstacle.h"
#include "../Entities/Npc.h"
#include "../Screens/InteractionScreen.h"


class ZoneBase {

    protected:
        sf::Texture backgroundTexture;
        sf::Sprite backgroundSprite;

        //vector of interactable objects

        lua_State *luaState;

        std::vector<Obstacle*> obstacles;
        // bool onBridge = false;
        TextureManager *tm;
        TextManager *ttm;
        ScreenManager *sm;
        sf::View *view;

    public:
        ZoneBase(TextureManager *tm, TextManager* ttm, ScreenManager *sm, sf::View *view);
        ~ZoneBase();

        void update(sf::Time deltaTime, float x, float y);
        void draw(sf::RenderWindow *window);
        void drawObstacles(AnimatedSprite *ani, sf::RenderWindow *window, TextureManager *tm);
        bool checkObstacleCollisin(AnimatedSprite *ani);
        bool checkNPCCollision(AnimatedSprite *ani);
        void drawScreens(sf::RenderWindow *window);

        //size is how big the window is (assuming the view is a square)
        void obstaclesInView(AnimatedSprite *ani, float size, TextureManager *tm);

        virtual bool renderObjectFirst(float playerX, float playerY) = 0;
        virtual bool checkPlayerConstraint(float x, float y) = 0;

        Npc npc;

};


#endif