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
    //have to reset movement vector
    this->player->movement = sf::Vector2f(0.f, 0.f);
};

void ActiveState::render(){
    this->player->render(this->window);
};

