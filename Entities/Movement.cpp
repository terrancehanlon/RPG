#include "Movement.h"

Movement::Movement(float movementSpeed){
    this->movementSpeed = movementSpeed;
      this->isMoving = false;
};

Movement::~Movement(){
    // this->movementSpeed = NULL;
};

void Movement::move(sf::Time deltaTime,AnimatedSprite *ani){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        //left
        // printf("A\n");
        this->movement.x -= this->movementSpeed;
        this->movement.y = 0;
        //return true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        //right
        // printf("D\n");
        this->movement.x += this->movementSpeed;
        this->movement.y = 0;
        //return true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        //up
        // printf("w\n");
        this->movement.x = 0;
        this->movement.y -= this->movementSpeed;
        //return true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        // printf("S\n");a
        //down
        this->movement.x = 0;
        this->movement.y += this->movementSpeed;
        //return true;
    }
    // ani->move(movement * deltaTime.asSeconds());
    // ani->move()
    // this->isMoving = rtn;

}

sf::Vector2f *Movement::getMovementVector(){
    return &this->movement;
}

void Movement::resetMovement(){
    this->movement.x = 0;
    this->movement.y = 0;
}