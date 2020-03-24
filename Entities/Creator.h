//Can be re structed for imports
#ifndef CREATOR_H
#define CREATOR_H
#include "./HumanPod.h"
#include "vector"
class Creator {

    public:
        std::vector<HumanPod*> rocks;
        Creator();
        
        void create(std::string key);
        void update(sf::Time dt);
        void render(sf::RenderWindow *win);


};


#endif