#include "StaticNpc.h"


void StaticNpc::init(TextureManager *tm){
    anim.setSpriteSheet(tm->getTexture("npc1"));
    printf("Texture got\n");
    anim.addFrame(sf::IntRect(43,24,11,15));
    anim.addFrame(sf::IntRect(139,25,11,14));
    anim.addFrame(sf::IntRect(235,24,11,15));
    ani.play(anim);
    ani.setPosition(sf::Vector2f(190,150));
    printf("pos set for npc\n");
};