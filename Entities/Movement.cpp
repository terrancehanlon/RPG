#include "Movement.h"

Movement::Movement(float movementSpeed){
    this->movementSpeed = movementSpeed;
    this->isMoving = false;
};

Movement::~Movement(){
    // this->movementSpeed = NULL;
};

bool Movement::move(sf::Time deltaTime, sf::Vector2f *movement, AnimatedSprite *ani){
    bool rtn = false;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        // printf("A\n");
        movement->x -= this->movementSpeed;
        rtn = true;
        //return true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        // printf("D\n");
        movement->x += this->movementSpeed;
        rtn = true;
        //return true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        // printf("w\n");
        movement->y -= this->movementSpeed;
        rtn = true;
        //return true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        // printf("S\n");a
        movement->y += this->movementSpeed;
        rtn = true;
        //return true;
    }
    // ani->move(*movement * deltaTime.asSeconds());
    // ani->move()
    // this->isMoving = rtn;
    return rtn;
}