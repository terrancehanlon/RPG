#include "./Creator.h"

Creator::Creator(){};

void Creator::create(std::string key){
    if(key == "hp"){
        //human pod
        printf("IS HP\n");
        HumanPod *hp = new HumanPod();
        hp->ani.setPosition(260, 550);
        this->rocks.push_back(hp);
    }
};

void Creator::update(sf::Time dt){
    for(int i = 0; i < this->rocks.size(); i++){
        this->rocks.at(i)->update(dt);
    }
};

void Creator::render(sf::RenderWindow *win){
    printf("%d\n", this->rocks.size());
    for(int i = 0; i < this->rocks.size(); i++){
        this->rocks.at(i)->render(win);
    }
}