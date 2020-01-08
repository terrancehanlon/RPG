#include "Game.h"

Game::Game(){
    this->init();
    this->states.push(new ActiveState(this->window));
};

Game::~Game(){}


void Game::init(){
    printf("Creating Window and initializing Game object\n");
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "RPG");
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
        frameTime = frameClock.restart();
        // this->update();
        // this->render();
        this->states.top()->update(frameTime);
        this->render();
    }
}