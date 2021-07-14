#include "InteractionScreen.h"
#include "DialogScreen.h"


void InteractionScreen::update(TextureManager *tm){
    // printf()
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)){
        // sf::Sprite s;
        // printf("pressing 1\n");
        // s.setTexture(tm->getTexture("dialogBox"));
        // // s.set_width(2560);
        // s.setPosition(baseImage.getPosition().x - (2560 / 2), baseImage.getPosition().y);
        // // DialogScreen *ds = new DialogScreen(this->tm, this->ttm, this->view);
        // // s.setPosition(s.getPosition().x, s.getPosition().y - 50);
        // // s.setScale(0.05f, 0.05f);
        // // sf::VideoMode::
        // std::cout << "video width: " << sf::VideoMode::getDesktopMode().width << std::endl;
        DialogScreen *ds = new DialogScreen(tm, ttm, view);
        ds->sprite.setPosition(baseImage.getPosition().x , baseImage.getPosition().y);
        ds->key = "dialog-screen";
        // baseImage = s;
        // this->sm->getSize();
        this->sm->addScreen(ds);
        tm->sw.diaglogActive = true;        
    }
}

void InteractionScreen::init(TextureManager *tm, TextManager *ttm){
    this->key = "interaction-screen";
    this->tm = tm;
    baseImage.setTexture(tm->getTexture("interaction-screen"));
    baseImage.setScale(sf::Vector2f(0.5f,0.5f));
    font.loadFromFile("Assets/fonts/OpenSans-Bold.ttf");
    text.setFont(font);
    text.setString(ttm->getText("dialog1"));
    text.setScale(0.1f, 0.1f);
    text.setPosition(baseImage.getPosition());
    text.setPosition(text.getPosition().x + 55, text.getPosition().y + 55);
}   