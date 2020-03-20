#include "./BloodCase.h"

BloodCase::BloodCase(){
    this->texture.loadFromFile("Assets/blood-case.png");

    this->anim.setSpriteSheet(this->texture);
    //NEED TO UPDATE coords based on new animation
    this->anim.addFrame(sf::IntRect(48, 94, 17, 30));
    this->anim.addFrame(sf::IntRect(172, 94, 17, 30));
    this->anim.addFrame(sf::IntRect(296, 94, 17, 30));
    this->anim.addFrame(sf::IntRect(420, 94, 17, 30));
    this->anim.addFrame(sf::IntRect(544, 94, 17, 30));
    this->anim.addFrame(sf::IntRect(668, 94, 17, 30));
    this->ani.play(this->anim);
};

void BloodCase::update(sf::Time dt){
    this->ani.update(dt);
};

void BloodCase::render(sf::RenderWindow *window){
    window->draw(this->ani);
};
