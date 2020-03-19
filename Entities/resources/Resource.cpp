#include "./Resource.h"

Resource::~Resource(){};

Resource::Resource(){
    this->blood = new Blood();
    // this->blood->ani.setPosition(sf::Vector2f(150.0f, 150.0f));
};

void Resource::update(sf::Time dt){
    // this->blood->ani.update(dt);
};

void Resource::render(sf::RenderWindow *window){ 
    this->blood->render(window);
    // window->draw(this->blood->ani);
}