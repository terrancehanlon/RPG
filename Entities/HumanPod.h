#ifndef HUMANPOD_H
#define HUMANPOD_H

// #include "../Lib/Imports.h"
#include "../Lib/TextureManager.h"
#include "./Rock.h"

class HumanPod {
    private:

    public:
        AnimatedSprite ani;
        Animation anim;

        sf::Texture texture;

        HumanPod(TextureManager *tm);

        void update(sf::Time dt);
        void render(sf::RenderWindow *window);

};


#endif