#include "./Blood.h"

Blood::Blood(TextureManager *tm){
    this->current = this->max;
    // if(!this->text.loadFromFile("Assets/blood-levels.png")){
    //     printf("cant find\n");
    // }else{
    //     printf("can find\n");
    // }
    // sf::Texture t = *(TextureManager::getInstance().getTexture("blood-levels"));
    this->anim.setSpriteSheet(tm->getTexture("blood-levels"));
    this->anim.addFrame(sf::IntRect(12, 37, 39, 80));
    // this->ani.play(this->anim);
    ani.play(this->anim);
    this->ani.setScale(0.10, 0.10);
    // this->ani.setPosition(sf::Vector2f(0.0f, 0.0f));
};

Blood::~Blood(){}

void Blood::update(sf::Time dt){
    this->ani.update(dt);
};

void Blood::render(sf::RenderWindow *window){
    // printf("drawing blood\n");
    // printf("%lf\n", this->ani.getPosition().x);
    window->draw(this->ani);
    // window->display();
}