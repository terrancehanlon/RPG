#ifndef BLOODCASE_H
#define BLOODCASE_H

#include "../Lib/Imports.h"

class BloodCase {

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