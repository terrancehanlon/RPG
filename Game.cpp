#include "Game.h"

Game::Game(){
    this->init();
    // this->states.push(new ActiveState(this->window));
    tm.addTexture("pixel", "/home/terrance/Desktop/games/RPG/Assets/pixel.png");
    tm.addTexture("new-walk", "Assets/new-walk.png");
    tm.addTexture("npc1", "Assets/base-walk.png");
    tm.addTexture("interaction-screen", "Assets/small-square-text.png");
    tm.addTexture("interaction-screen-select-1", "Assets/small-sqaure-text-select.png");
    tm.addTexture("tree", "Assets/obst-tree.png");
    tm.addTexture("stream", "Assets/water.png");
    tm.addTexture("bridge", "Assets/bridge.png");
    tm.addTexture("blood-levels", "Assets/blood-levels.png");
    tm.addTexture("dialog1", "Assets/dialog1.png");
    // tm.getSize();
    this->states.push(new ActiveState(&tm));
    this->states.push(new Menu(&tm));
};

Game::~Game(){}


void Game::init(){
    printf("Creating Window and initializing Game object now\n");
    this->window = new sf::RenderWindow(sf::VideoMode(1024, 1024), "RPG", sf::Style::Close | sf::Style::Resize);
    // this->window = new sf::RenderWindow(sf::VideoMode(1024, 1024), "RPG", sf::Style::Fullscreen);
    // this->view = new sf::View(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1024.0f, 512.0f));
};


void Game::update(){

};

void Game::render(){
    this->window->clear();
    this->states.top()->render(this->window);
    this->window->display();
};

void Game::run(){
    printf("Game running \n");
    sf::Clock frameClock;
    sf::Time frameTime;

    // lua_State* L = luaL_newstate();
    // luaL_loadfile(L, "Zones/constraints/zone1.lua");
    // lua_pcall(L, 0, 1, 0);
    // auto waterRef = luabridge::
    // lua_getglobal(L, "")
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
        if(this->states.top()->stateFinished){
            this->states.pop();
            this->states.top()->init();
        }
        this->states.top()->update(frameTime);
        this->render();
    }
}