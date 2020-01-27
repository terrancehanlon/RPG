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

void Movement::backPeddle(AnimatedSprite *ani, sf::View *view){
    ani->move(sf::Vector2f(-0.05f, 0.0f));
}

void Movement::move(sf::Time deltaTime,AnimatedSprite *ani, sf::View *view){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::J)){
        printf("=====================================\n");
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::U)){
        printf("x: %f y: %f \n", getPlayerX(ani), getPlayerY(ani));
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        //left
        // printf("A\n");
        //two if statements so view doesnt follow when near end of map  
        if((getPlayerX(ani) - 124) < 0 || (getPlayerY(ani) - 124) < 0){
            ani->move(sf::Vector2f(-0.05f, 0.0f));
            
        }else{
            ani->move(sf::Vector2f(-0.05f, 0.0f));
            view->move(sf::Vector2f(-0.05f, 0.0f));
            view->setCenter(this->getPlayerX(ani), this->getPlayerY(ani));
        }   
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        //right
        if((getPlayerX(ani) - 124) < 0 || (getPlayerY(ani) - 124) < 0){
            ani->move(sf::Vector2f(0.05f, 0.0f));

        }
        else{
            ani->move(sf::Vector2f(0.05f, 0.0f));
            view->move(sf::Vector2f(0.05f, 0.0f));
            view->setCenter(this->getPlayerX(ani), this->getPlayerY(ani));
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        //up
        if((getPlayerX(ani) - 124) < 0 || (getPlayerY(ani) - 124) < 0){
            ani->move(sf::Vector2f(0.00f, -0.05f));
        }
        else{
            ani->move(sf::Vector2f(0.00f, -0.05f));
            view->move(sf::Vector2f(0.00f, -0.05f));
            view->setCenter(this->getPlayerX(ani), this->getPlayerY(ani));
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        // printf("S\n");a
        if((getPlayerX(ani) - 124) < 0 || (getPlayerY(ani) - 124) < 0){
            ani->move(sf::Vector2f(0.00f, 0.05f));

        }
        else{
            ani->move(sf::Vector2f(0.00f, 0.05f));
            view->move(sf::Vector2f(0.00f, 0.05f));
            view->setCenter(this->getPlayerX(ani), this->getPlayerY(ani));
        }
    }

}

sf::Vector2f *Movement::getMovementVector(){
    return &this->movement;
}

void Movement::resetMovement(){
    this->movement.x = 0;
    this->movement.y = 0;
}