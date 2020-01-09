#include "Movement.h"

Movement::Movement(float movementSpeed){
    this->movementSpeed = movementSpeed;
};

Movement::~Movement(){
    // this->movementSpeed = NULL;
};

bool Movement::move(sf::Time deltaTime, sf::Vector2f *movement){
    bool rtn = false;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        movement->x -= this->movementSpeed;
        rtn = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        movement->x += this->movementSpeed;
        rtn = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {

        movement->y -= this->movementSpeed;
        rtn = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        movement->y += this->movementSpeed;
        rtn = true;
    }
    return rtn;
}