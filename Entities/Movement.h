#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "./BloodCase.h"

class Movement {

    private:
        float movementSpeed;
        sf::Vector2f movement;
        const float OFFSET = 1000;

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
        //1 left, 0 right
        void backPeddle(AnimatedSprite *ani, AnimatedSprite *blood, sf::View *view) ;

        //1 for left
        //2 for right
        int direction = 0;

};

#endif