#include "ActiveState.h"

ActiveState::ActiveState(sf::RenderWindow *window) : State(window){
    printf("Creating active state\n");
    this->zones.push(new Zone());
    this->player = new Entity();
    this->initState();
    this->view = new sf::View(sf::Vector2f(1024.0f, 1024.0f), sf::Vector2f(124.0f, 124.0f));
};

void ActiveState::initState(){
    printf("Initilaizing ActiveState\n");
    //draw state (zone)
    this->window->clear(sf::Color::Magenta);    
};

void ActiveState::update(sf::Time dt){
    //zone.update(dt)
    // this->view->setCenter(this->player->ani.getPosition().x, this->player->ani.getPosition().y);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        // this->view->move(this->movementSpeed, 0.0f);
        // this->view->setCenter(250.0f, 250.0f);
        if(this->player->ani.getPosition().x >= 324.0f){
            printf("WATER\n");
        }
        else{
        this->player->ani.move(sf::Vector2f(0.05f, 0.0f));
            this->view->move(sf::Vector2f(0.05f, 0.0f));
            this->view->setCenter(this->player->ani.getPosition().x, this->player->ani.getPosition().y);
        }
        // printf("x: %lf y: %lf\n", this->player->ani.getPosition().x, this->player->ani.getPosition().y);
        // this->
    }
     if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        // this->view->move(this->movementSpeed, 0.0f);
        // this->view->setCenter(250.0f, 250.0f);
        this->player->ani.move(sf::Vector2f(0.0f, 0.05f));
        this->view->move(sf::Vector2f(0.0f, 0.05f));
        this->view->setCenter(this->player->ani.getPosition().x, this->player->ani.getPosition().y);
        // this->
    }
    this->player->update(dt);
    this->player->resetMovement();
};

void ActiveState::render(){
    this->window->setView(*this->view); 
    this->zones.top()->draw(this->window);
    this->player->render(this->window);
};

