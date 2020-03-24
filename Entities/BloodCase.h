#ifndef BLOODCASE_H
#define BLOODCASE_H

#include "./HumanPod.h"
#include "./Rock.h"

class BloodCase{

  private:

  public:
    AnimatedSprite ani;
    Animation anim;

    sf::Texture texture;

    BloodCase();

    void update(sf::Time dt);
    void render(sf::RenderWindow *window);

};

#endif