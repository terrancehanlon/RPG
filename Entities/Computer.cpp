#include "Computer.h"


Computer::Computer(){
    this->text.loadFromFile("Assets/computer.png");
    this->anim.setSpriteSheet(this->text);
    this->initGraphics();
    this->ani.play(this->anim);
    this->screen = new ComputerScreen();
    // this->~Computer
}

void Computer::initGraphics(){
    this->anim.addFrame(sf::IntRect(24,10,49, 50));
    this->anim.addFrame(sf::IntRect(104,10, 49, 50));
    this->anim.addFrame(sf::IntRect(184,10, 49, 50));
    this->ani.play(this->anim);
}

void Computer::update(sf::Time dt, bool onScreen){
    if(onScreen){
        this->screen->update(dt);
    }else{
        this->screen->update(dt);
        this->ani.update(dt);
    }

}

void Computer::draw(sf::RenderWindow *window, bool onScreen){
    if(onScreen){
        this->screen->render(window);
    }
    else{
        window->draw(this->ani);
    }
}

void Computer::displayerscreen(sf::RenderWindow *window){
    this->screen->render(window);
    // this->update
}

Computer::~Computer(){
    delete &this->ani;
    delete &this->anim;
    delete &this->text;
}