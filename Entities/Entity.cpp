#include "Entity.h"

Entity::Entity(){
    // this->ani = *new AnimatedSprite();
    this->movementSpeed = 1.0f;
    this->movementComp = new Movement(this->movementSpeed);
    text.loadFromFile("Assets/pixel.png");
    anim.setSpriteSheet(text);
    anim.addFrame(sf::IntRect(0, 0, 24, 24));
    anim.addFrame(sf::IntRect(24, 0, 24, 24));
    anim.addFrame(sf::IntRect(48, 0, 24, 24));
    anim.addFrame(sf::IntRect(72, 0, 24, 24));
    anim.addFrame(sf::IntRect(96, 0, 24, 24));
    anim.addFrame(sf::IntRect(120, 0, 24, 24));
    anim.addFrame(sf::IntRect(144, 0, 24, 24));

    // this->ani.setOrigin(this->ani.getPosition()/2.0f);
    // this->ani.getGlobalBounds
    // this->ani.setOrigin(sf::Vector2f(this->ani.getGlobalBounds())
    // this->view = new sf::View(sf::Vector2f(250.0f, 250.0f), sf::Vector2f(512.0f, 512.0f));
    // ani.setScale(5, 5);

    this->ani.setPosition(sf::Vector2f(150.0f, 150.0f));

    ani.play(anim);
    
};

void Entity::update(sf::Time deltaTime){
    this->ani.update(deltaTime);  
    // this->view->setCenter(sf::Vector2f(this->ani.getPosition().x, this->ani.getPosition().y));  
    // if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    //     this->moveLeft(deltaTime);
    // if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
    //     // this->view->move(this->movementSpeed, 0.0f);
    //     // this->view->setCenter(250.0f, 250.0f);
    //     this->view->move(sf::Vector2f(0.05f, 0.0f));
    // }
        //this->moveRight(deltaTime);   
    // if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    //     this->moveUp(deltaTime);   
    // if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    //     this->moveDown(deltaTime);   

    // this->movementComp->move(deltaTime, &this->ani);
    // this->ani.move(*this->movementComp->getMovementVector() * deltaTime.asSeconds());
}

void Entity::moveRight(sf::Time deltaTime){
    this->movement.x += this->movementSpeed;
    this->movement.y = 0;
    this->ani.move(this->movement * deltaTime.asSeconds());
}
void Entity::moveLeft(sf::Time deltaTime){
    this->movement.x -= this->movementSpeed;
    this->movement.y = 0;
    this->ani.move(this->movement * deltaTime.asSeconds());
}
void Entity::moveUp(sf::Time deltaTime){
    this->movement.y -= this->movementSpeed;
    this->movement.x = 0;
    this->ani.move(this->movement * deltaTime.asSeconds());
}
void Entity::moveDown(sf::Time deltaTime){
    this->movement.y += this->movementSpeed;
    this->movement.x = 0;
    this->ani.move(this->movement * deltaTime.asSeconds());
}

void Entity::move(sf::Time deltaTime, float x, float y){
    //this->movement.x += (this->movementSpeed);
    // this->ani.move(this->movement * deltaTime.asSeconds());
    this->movement.x = x;
    this->movement.y = y;
    this->ani.move( (this->movement * deltaTime.asSeconds()) * 5.f);
}

void Entity::resetMovement(){
    // this->movement.x = 0;
    // this->movement.y = 0;
    // this->movementComp->resetMovement();
    // this->ani.stop();
}

void Entity::render(sf::RenderWindow *window){
    // window->setView(*this->view);
    window->draw(this->ani);
}