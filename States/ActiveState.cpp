#include "ActiveState.h"

ActiveState::ActiveState(sf::RenderWindow *window) : State(window){
    printf("Creating active state\n");
    this->zones.push(new Zone());
    this->player = new Entity();
    this->initState();
    this->view = new sf::View(sf::Vector2f(1024.0f, 1024.0f), sf::Vector2f(124.0f, 124.0f));
    this->movementComp = new Movement(0.055f);
};

void ActiveState::initState(){
    printf("Initilaizing ActiveState\n");
    //draw state (zone)
    this->window->clear(sf::Color::Magenta);    
};

void ActiveState::update(sf::Time dt){
    this->movementComp->move(dt, &this->player->ani, this->view);
    this->player->update(dt);
    this->player->resetMovement();
};

void ActiveState::render(){
    this->window->setView(*this->view); 
    this->zones.top()->draw(this->window);
    this->player->render(this->window);
};

