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
    name.assign("tree");
}

void Obstacle::stream(){
    name.assign("stream");
}


void Obstacle::bridge(){
    name.assign("bridge");
}

void Obstacle::show(TextureManager *tm){
    // texture = sf::Texture();
    // printf("name: %s", name);
    // texutre->loadf
    this->visible = true;
    if(name == "bridge"){
        // if(!texture->loadfromfile("Assets/bridge.png")){
        //     printf("cannot find bridge asset\n");
        // }
        // sf::Texture t = *(TextureManager::getInstance().getTexture("bridge"));
        anim.setSpriteSheet(tm->getTexture("bridge"));
        anim.addFrame(sf::IntRect(-1,0,313,235));
        ani.setAnimation(anim);
        ani.play(anim);
        ani.setScale(sf::Vector2f(0.15,0.15));
        ani.setPosition(sf::Vector2f(80, 300));
        this->isHard = true;
    }
    if(name == "stream"){
        // printf("Creating stream\n");
        anim.setSpriteSheet(tm->getTexture("stream"));
        anim.addFrame(sf::IntRect(0,0,16,512));
        ani.setAnimation(anim);
        ani.setPosition(sf::Vector2f(95, 0));
        this->isHard = true;
    }
    if(name == "tree"){
        anim.setSpriteSheet(tm->getTexture("tree"));
        anim.addFrame(sf::IntRect(56,21,288,444));
        ani.setAnimation(anim);
        ani.play(anim);
        ani.setScale(sf::Vector2f(0.25,0.25));

        // ani.setPosition(sf::Vector2f(60,450));
        this->isHard = false;
    }
}

void Obstacle::unshow(){
    // delete texture;
}