#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "../Lib/Imports.h"

class Movement {

    private:
        float movementSpeed;

    public:
        Movement(float movementSpeed);
        ~Movement();

        bool move(sf::Time deltaTime,sf::Vector2f *movement);
        void setMove(sf::Vector2f *movement);


};

#endif