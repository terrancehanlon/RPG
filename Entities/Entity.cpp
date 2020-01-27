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
    /*  this function updates the animation of the sprite
        all the movement functionality is done within Movement.h this is how to follow a more "composition over inheritance" ideology
        the ActiveState.h is what utilizes the Movement.h functions.
    */
}


void Entity::render(sf::RenderWindow *window){
    // window->setView(*this->view);
    window->draw(this->ani);
}