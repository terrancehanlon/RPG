#include "Computer.h"


Computer::Computer(){
    this->text.loadFromFile("Assets/computer.png");
    this->anim.setSpriteSheet(this->text);
    this->initGraphics();
    this->ani.play(this->anim);
}

void Computer::initGraphics(){
    this->anim.addFrame(sf::IntRect(24,10,49, 50));
    this->anim.addFrame(sf::IntRect(104,10, 49, 50));
    this->anim.addFrame(sf::IntRect(184,10, 49, 50));
    this->ani.play(this->anim);
}

void Computer::update(sf::Time dt){
    this->ani.update(dt);

}

void Computer::draw(sf::RenderWindow *window){
    // printf("Drawing comp\n");
    window->draw(this->ani);
}

Computer::~Computer(){}