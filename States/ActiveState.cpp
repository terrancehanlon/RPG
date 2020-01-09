#include "ActiveState.h"

ActiveState::ActiveState(sf::RenderWindow *window) : State(window){
    printf("Creating active state\n");
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
};

void ActiveState::render(){
    this->player->render(this->window);
};

