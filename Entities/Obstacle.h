#ifndef OBSTACLE_H
#define OBSTACLE_H

#pragma once


#include "../Lib/Imports.h"

class Obstacle {


    public:
        Obstacle();
        ~Obstacle();

        void render(sf::RenderWindow* window);
        void update(sf::Time dt);

        void tree();
        
    private:
        sf::Texture texture;
        AnimatedSprite ani;
        Animation anim;



};


#endif