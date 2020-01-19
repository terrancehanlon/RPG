#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "../Lib/Imports.h"

class Movement {

    private:
        float movementSpeed;
        sf::Vector2f movement;

    public:
        bool isMoving;
        Movement(float movementSpeed);
        ~Movement();

        void move(sf::Time deltaTime, AnimatedSprite *ani, sf::View *view);
        float getPlayerX(AnimatedSprite *ani);
        float getPlayerY(AnimatedSprite *ani);
        void setMove(sf::Vector2f *movement);
        sf::Vector2f *getMovementVector();
        void resetMovement();

};

#endif