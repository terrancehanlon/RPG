#include "Entity.h"

Entity::Entity(){
    // this->ani = *new AnimatedSprite();
    this->movementSpeed = 0.005f;
    text.loadFromFile("/home/terrance/desktop/games2/rpg/src/Assets/pixel.png");
    anim.setSpriteSheet(text);
    anim.addFrame(sf::IntRect(0, 0, 24, 24));
    anim.addFrame(sf::IntRect(24, 0, 24, 24));
    anim.addFrame(sf::IntRect(48, 0, 24, 24));
    anim.addFrame(sf::IntRect(72, 0, 24, 24));
    anim.addFrame(sf::IntRect(96, 0, 24, 24));
    anim.addFrame(sf::IntRect(120, 0, 24, 24));
    anim.addFrame(sf::IntRect(144, 0, 24, 24));

    // ani.setScale(5, 5);

    ani.play(anim);
};

void Entity::update(sf::Time deltaTime){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->move(deltaTime, -1.f, 0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->move(deltaTime, 1.f, 0.f);   
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->move(deltaTime, 0.f, -1.f);   
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->move(deltaTime, 0.f, 1.f);   
}

void Entity::move(sf::Time deltaTime, float x, float y){

    this->movement.x += (this->movementSpeed);
    this->ani.move(this->movement * deltaTime.asSeconds());
}

void Entity::render(sf::RenderWindow *window){
    printf("Drawing PLayer\n"); 
    window->draw(this->ani);
}