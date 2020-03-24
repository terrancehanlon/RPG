#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "./BloodCase.h"

class Movement {

    private:
        float movementSpeed;
        sf::Vector2f movement;

    public:
        bool isMoving;
        Movement(float movementSpeed);
        ~Movement();
        bool create = false;
        void move(sf::Time deltaTime, AnimatedSprite *ani, AnimatedSprite *blood, sf::View *view);
        float getPlayerX(AnimatedSprite *ani);
        float getPlayerY(AnimatedSprite *ani);
        void setMove(sf::Vector2f *movement);
        sf::Vector2f *getMovementVector();
        void resetMovement();
        void backPeddle(AnimatedSprite *ani, AnimatedSprite *blood, sf::View *view) ;

};

#endif