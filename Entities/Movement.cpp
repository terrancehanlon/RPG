#include "Movement.h"

Movement::Movement(float movementSpeed){
    this->movementSpeed = movementSpeed;
      this->isMoving = false;
};

Movement::~Movement(){
    // this->movementSpeed = NULL;
};

float Movement::getPlayerX(AnimatedSprite *ani){
    return ani->getPosition().x;
}

float Movement::getPlayerY(AnimatedSprite *ani){
    return ani->getPosition().y;
}

void Movement::move(sf::Time deltaTime,AnimatedSprite *ani, sf::View *view){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        //left
        // printf("A\n");
        ani->move(sf::Vector2f(-0.05f, 0.0f));
        view->move(sf::Vector2f(-0.05f, 0.0f));
        view->setCenter(this->getPlayerX(ani), this->getPlayerY(ani));
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        //right
        ani->move(sf::Vector2f(0.05f, 0.0f));
        view->move(sf::Vector2f(0.05f, 0.0f));
        view->setCenter(this->getPlayerX(ani), this->getPlayerY(ani));
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        //up
        ani->move(sf::Vector2f(0.00f, -0.05f));
        view->move(sf::Vector2f(0.00f, -0.05f));
        view->setCenter(this->getPlayerX(ani), this->getPlayerY(ani));
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        // printf("S\n");a
        ani->move(sf::Vector2f(0.00f, 0.05f));
        view->move(sf::Vector2f(0.00f, 0.05f));
        view->setCenter(this->getPlayerX(ani), this->getPlayerY(ani));
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