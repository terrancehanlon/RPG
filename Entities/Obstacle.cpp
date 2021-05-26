#include "Obstacle.h"


Obstacle::Obstacle(){

}

Obstacle::~Obstacle(){}


void Obstacle::update(sf::Time dt){
    ani.update(dt);
}
void Obstacle::render(sf::RenderWindow* window){
    window->draw(ani);
}

void Obstacle::tree(){
    printf("Creating tree\n");
    if(!texture.loadFromFile("Assets/obst-tree.png")){
        printf("cant find file for tree\n");
    }
    anim.setSpriteSheet(texture);
    anim.addFrame(sf::IntRect(56,21,288,444));
    ani.setAnimation(anim);
    ani.play(anim);
    ani.setScale(sf::Vector2f(0.25,0.25));

    ani.setPosition(sf::Vector2f(60,450));
}