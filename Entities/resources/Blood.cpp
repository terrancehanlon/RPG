#include "./Blood.h"

Blood::Blood(){
    this->current = this->max;
    this->text.loadFromFile("Assets/blood-levels.png");
    this->sprite.setTexture(this->text);
};

Blood::~Blood(){}

void Blood::update(sf::Time dt){
    
};

void Blood::render(sf::RenderWindow *window){
    window->draw(this->sprite);
}