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
    printf("updating\n");
    this->player->update(dt);
};

void ActiveState::render(){
    printf("Rendering\n");
    this->player->render(this->window);
};

