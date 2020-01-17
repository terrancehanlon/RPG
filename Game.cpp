#include "Game.h"

Game::Game(){
    this->init();
    this->states.push(new ActiveState(this->window));
};

Game::~Game(){}


void Game::init(){
    printf("Creating Window and initializing Game object\n");
    this->window = new sf::RenderWindow(sf::VideoMode(1024, 1024), "RPG", sf::Style::Close | sf::Style::Resize);
    // this->view = new sf::View(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1024.0f, 512.0f));
};


void Game::update(){

};

void Game::render(){
    this->window->clear();
    this->states.top()->render();
    this->window->display();
};

void Game::run(){
    sf::Clock frameClock;
    sf::Time frameTime;
    while(this->window->isOpen()){
        sf::Event event;
        while(window->pollEvent(event)){
            // switch(event.type){
                // case sf::Event::Resized:
                    // 
            // }
        }
        frameTime = frameClock.restart();
        // this->update();
        // this->render();
        this->states.top()->update(frameTime);
        this->render();
    }
}