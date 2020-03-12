#include "ComputerScreen.h"

ComputerScreen::ComputerScreen(){
    this->txt.loadFromFile("Assets/comp-screen.png");
    this->anim.setSpriteSheet(this->txt);
    this->initgraphics();
    this->ani.play(this->anim);
};


void ComputerScreen::update(sf::Time dt){
    printf("Updating screen \n");
    this->ani.update(dt);
};

void ComputerScreen::render(sf::RenderWindow* window){
    // this->ani.update(dt);
    printf("rendering screen\n");
    // this->ani.play(this->anim);
    window->draw(this->ani);
    // window->display();
};

void ComputerScreen::initgraphics(){
    this->anim.addFrame(sf::IntRect(0,0, 110, 110));
    this->anim.addFrame(sf::IntRect(110,0,110,110));
    // this->ani.play(this->anim);
}