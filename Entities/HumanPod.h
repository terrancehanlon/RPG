#ifndef HUMANPOD_H
#define HUMANPOD_H

#include "../Lib/Imports.h"
#include "./Rock.h"

class HumanPod : public Rock {
    private:

    public:
        AnimatedSprite ani;
        Animation anim;

        sf::Texture texture;

        HumanPod();

        void update(sf::Time dt);
        void render(sf::RenderWindow *window);

};


#endif