#include "./BloodCase.h"

BloodCase::BloodCase(){
    this->texture.loadFromFile("Assets/blood-case.png");

    this->anim.setSpriteSheet(this->texture);
    //NEED TO UPDATE coords based on new animation
    this->anim.addFrame(sf::IntRect(32, 82, 17, 35));
    this->anim.addFrame(sf::IntRect(156, 82, 17, 35));
    this->anim.addFrame(sf::IntRect(280, 82, 17, 35));
    this->anim.addFrame(sf::IntRect(404, 82, 17, 35));
    this->anim.addFrame(sf::IntRect(528, 82, 17, 35));
    this->anim.addFrame(sf::IntRect(652, 82, 17, 35));
    this->ani.play(this->anim);
};

void BloodCase::update(sf::Time dt){
    this->ani.update(dt);
};

void BloodCase::render(sf::RenderWindow *window){
    window->draw(this->ani);
};
