#include "ActiveState.h"

ActiveState::ActiveState(sf::RenderWindow *window) : State(window){
    printf("Creating active state\n");
    this->zones.push(new Zone());
    this->player = new Entity();
    this->initState();
};

void ActiveState::initState(){
    printf("Initilaizing ActiveState\n");
    //draw state (zone)
    this->window->clear(sf::Color::Magenta);    
};

void ActiveState::update(sf::Time dt){
    //zone.update(dt)
    this->player->update(dt);
    this->player->resetMovement();
};

void ActiveState::render(){
    this->zones.top()->draw(this->window);
    this->player->render(this->window);
};

