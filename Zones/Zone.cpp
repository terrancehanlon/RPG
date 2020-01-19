#include "Zone.h"

Zone::Zone(){
    this->texture.loadFromFile("Assets/rpg-zone1.png");
    this->sprite.setTexture(this->texture);  
}


Zone::~Zone(){
    delete &this->sprite;
    delete &this->texture;
}


void Zone::draw(sf::RenderWindow *window){
    window->draw(this->sprite);
}

void Zone::update(sf::Time deltaTime, float x, float y, sf::RenderWindow *window){
    if( (window->getSize().y) < y){
        // printf("Player below screen\n");
        //this->sprite.setPosition(this->sprite.getPosition().x, this->sprite.getPosition().y - 1);
        // this->
    }
    // sf::Style::Fullscreen-
}