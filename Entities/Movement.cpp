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

void Movement::backPeddle(AnimatedSprite *ani, AnimatedSprite *blood, sf::View *view){
    ani->move(sf::Vector2f(-0.05f, 0.0f));
    blood->move(sf::Vector2f(-0.05f, 0.0f));
}

void Movement::move(sf::Time deltaTime,AnimatedSprite *ani, AnimatedSprite *blood, sf::View *view){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::J)){
        printf("=====================================\n");
        printf("x: %f y: %f", ani->getPosition().x, ani->getPosition().y);
        this->create = true; 
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::U)){
        printf("x: %f y: %f \n", getPlayerX(ani), getPlayerY(ani));

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        this->create = false;
        //left
        // printf("A\n");
        //two if statements so view doesnt follow when near end of map  
        if((getPlayerX(ani) - 124) < 0 || (getPlayerY(ani) - 124) < 0){
            ani->move(this->OFFSET * deltaTime.asSeconds() * sf::Vector2f(-0.05f, 0.0f));
            blood->move(this->OFFSET * deltaTime.asSeconds() * sf::Vector2f(-0.05f, 0.0f));

            //comment out if want to view to stop
             view->move(this->OFFSET * deltaTime.asSeconds() * sf::Vector2f(-0.05f, 0.0f));
            view->setCenter(this->getPlayerX(ani), this->getPlayerY(ani));
            
        }else{
            ani->move(this->OFFSET * deltaTime.asSeconds() * sf::Vector2f(-0.05f, 0.0f));
            blood->move(this->OFFSET * deltaTime.asSeconds() * sf::Vector2f(-0.05f, 0.0f));
            view->move(this->OFFSET * deltaTime.asSeconds() * sf::Vector2f(-0.05f, 0.0f));
            view->setCenter(this->getPlayerX(ani), this->getPlayerY(ani));
        }   
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        //right
        if((getPlayerX(ani) - 124) < 0 || (getPlayerY(ani) - 124) < 0){
            ani->move(sf::Vector2f(0.05f * deltaTime.asSeconds() * this->OFFSET, 0.0f));
            blood->move(this->OFFSET * deltaTime.asSeconds() * sf::Vector2f(0.05f, 0.0f));
            
            //comment out if want to view to stop
             view->move(this->OFFSET * deltaTime.asSeconds() * sf::Vector2f(-0.05f, 0.0f));     
            view->setCenter(this->getPlayerX(ani), this->getPlayerY(ani));
        }
        else{
            ani->move(this->OFFSET * deltaTime.asSeconds() * sf::Vector2f(0.05f, 0.0f));
            blood->move(this->OFFSET * deltaTime.asSeconds() * sf::Vector2f(0.05f, 0.0f));
            view->move(this->OFFSET * deltaTime.asSeconds() * sf::Vector2f(0.05f, 0.0f));
            view->setCenter(this->getPlayerX(ani), this->getPlayerY(ani));
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        //up
        if((getPlayerX(ani) - 124) < 0 || (getPlayerY(ani) - 124) < 0){
            ani->move(this->OFFSET * deltaTime.asSeconds() * sf::Vector2f(0.00f, -0.05f));
            blood->move(this->OFFSET * deltaTime.asSeconds() * sf::Vector2f(0.00f, -0.05f));


            //comment out if want to view to stop
             view->move(this->OFFSET * deltaTime.asSeconds() * sf::Vector2f(-0.05f, 0.0f));
            view->setCenter(this->getPlayerX(ani), this->getPlayerY(ani));
        }
        else{
            ani->move(this->OFFSET * deltaTime.asSeconds() * sf::Vector2f(0.00f, -0.05f));
            blood->move(this->OFFSET * deltaTime.asSeconds() * sf::Vector2f(0.00f, -0.05f));
            view->move(this->OFFSET * deltaTime.asSeconds() * sf::Vector2f(0.00f, -0.05f));
            view->setCenter(this->getPlayerX(ani), this->getPlayerY(ani));
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        if((getPlayerX(ani) - 124) < 0 || (getPlayerY(ani) - 124) < 0){
            ani->move(this->OFFSET * deltaTime.asSeconds() * sf::Vector2f(0.00f, 0.05f));
            blood->move(this->OFFSET * deltaTime.asSeconds() * sf::Vector2f(0.00f, 0.05f));


            //comment out if want to view to stop
             view->move(this->OFFSET * deltaTime.asSeconds() * sf::Vector2f(-0.05f, 0.0f));
            view->setCenter(this->getPlayerX(ani), this->getPlayerY(ani));
        }
        else{
            ani->move(this->OFFSET * deltaTime.asSeconds() * sf::Vector2f(0.00f, 0.05f));
            blood->move(this->OFFSET * deltaTime.asSeconds() * sf::Vector2f(0.00f, 0.05f));
            view->move(this->OFFSET * deltaTime.asSeconds() * sf::Vector2f(0.00f, 0.05f));
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