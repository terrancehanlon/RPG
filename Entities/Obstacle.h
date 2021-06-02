#ifndef OBSTACLE_H
#define OBSTACLE_H

#pragma once


// #include "../Lib/Imports.h"
#include "../Lib/TextureManager.h"
class Obstacle {


    public:
        Obstacle();
        ~Obstacle();

        void render(sf::RenderWindow* window);
        void update(sf::Time dt);

        void tree();
        AnimatedSprite ani;

        void stream();
        void bridge();

        void show(TextureManager *tm);

        bool isHard = false;

        void unshow();

        bool visible = false;
        std::string name;
        
    protected:
        Animation anim;




};


#endif