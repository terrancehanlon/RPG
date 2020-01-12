#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "../Lib/Imports.h"

class Movement {

    private:
        float movementSpeed;

    public:
        bool isMoving;
        Movement(float movementSpeed);
        ~Movement();

        bool move(sf::Time deltaTime,sf::Vector2f *movement, AnimatedSprite *ani);
        void setMove(sf::Vector2f *movement);


};

#endif