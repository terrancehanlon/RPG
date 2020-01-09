#ifndef ENTITY_H
#define ENTITY_H


#include "../Lib/Imports.h"
#include "../States/State.h"


// #include <vector>
#include <stack>
#include "Movement.h"
class Entity
{
    private:
        Movement *movementComp;



    public:
        sf::Vector2f movement;
        float movementSpeed;
        Entity();
        AnimatedSprite ani;
        Animation anim;
        sf::Texture text;

        void update(sf::Time deltaTime);
        void move(sf::Time deltaTime, float x, float y);

        void render(sf::RenderWindow *window);

};

#endif

