#include "./HumanPod.h"


HumanPod::HumanPod(){
    this->texture.loadFromFile("Assets/human-pod.png");
    this->anim.setSpriteSheet(this->texture);
    this->anim.addFrame(sf::IntRect(246, 281, 29, 49));
    this->anim.addFrame(sf::IntRect(858, 281, 29, 49));
    this->anim.addFrame(sf::IntRect(1470, 281, 29, 49));
    this->anim.addFrame(sf::IntRect(2082, 281, 29, 49));
    this->anim.addFrame(sf::IntRect(2694, 281, 29, 49));
    this->anim.addFrame(sf::IntRect(3306, 281, 29, 49));
    this->anim.addFrame(sf::IntRect(3918, 281, 29, 49));
    this->anim.addFrame(sf::IntRect(4530, 281, 29, 49));
    this->anim.addFrame(sf::IntRect(5142, 281, 29, 49));
    this->anim.addFrame(sf::IntRect(5754, 281, 29, 49));
    this->anim.addFrame(sf::IntRect(6366, 281, 29, 49));
    this->anim.addFrame(sf::IntRect(6978, 281, 29, 49));
    this->anim.addFrame(sf::IntRect(7590, 281, 29, 49));
    this->anim.addFrame(sf::IntRect(8202, 281, 29, 49));
    this->anim.addFrame(sf::IntRect(8814, 281, 29, 49));
    this->anim.addFrame(sf::IntRect(9426, 281, 29, 49));
    this->anim.addFrame(sf::IntRect(10038, 281, 29, 49));
    this->anim.addFrame(sf::IntRect(10650, 281, 29, 49));
    this->anim.addFrame(sf::IntRect(11262, 281, 29, 49));
    this->anim.addFrame(sf::IntRect(11874, 281, 29, 49));

    this->ani.play(this->anim);

};

void HumanPod::update(sf::Time dt){
    this->ani.update(dt);
};

void HumanPod::render(sf::RenderWindow *window){
    window->draw(this->ani);
}