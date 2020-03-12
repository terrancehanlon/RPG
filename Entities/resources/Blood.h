#ifndef BLOOD_H
#define BLOOD_H

#include "../../Lib/Imports.h"

class Blood {
    
    private:
            sf::Texture text;

    public:
        sf::Sprite sprite; //single animation so sprite is only needed
        //change these to private later?
        int max = 100;
        int current;
        Blood();
        ~Blood();
        void update(sf::Time dt);
        void render(sf::RenderWindow *window);  
};

#endif