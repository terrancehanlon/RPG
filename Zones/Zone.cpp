#include "Zone.h"

Zone::Zone(){
    this->texture.loadFromFile("Assets/rpg-zone1.png");
    // this->image.loadFromFile("Assets/rpg-zone1.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setScale(5, 5);    
}


Zone::~Zone(){
    delete &this->image;
    delete &this->texture;
}


void Zone::draw(sf::RenderWindow *window){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::G)){
        this->sprite.setPosition(this->sprite.getPosition().x - 0.5f, this->sprite.getPosition().y);
    }
    window->draw(this->sprite);
}

void Zone::update(sf::Time deltaTime, float x, float y){
    
}