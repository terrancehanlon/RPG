#ifndef BLOOD_H
#define BLOOD_H

// #include "../../Lib/Imports.h"
#include "../../Lib/TextureManager.h"

class Blood {
    
    private:

    public:
        // sf::Texture text;
        AnimatedSprite ani; //single animation so sprite is only needed
        Animation anim;
        //change these to private later?
        int max = 100;
        int current;
        Blood(TextureManager *tm);
        ~Blood();
        void update(sf::Time dt);
        void render(sf::RenderWindow *window);  
};

#endif