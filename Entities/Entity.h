#ifndef ENTITY_H
#define ENTITY_H

#include "../States/State.h"


// #include <vector>
#include <stack>
#include "Movement.h"
#include "Storage.h"
#include "./resources/Resource.h"
class Entity
{
    private:
        Movement *movementComp;


    public:
        sf::View *view;
        sf::Vector2f movement;
        float movementSpeed;
        Entity(TextureManager *tm);
        AnimatedSprite ani;
        Animation anim;
        sf::Texture text;

        Storage inventory;
        
        void update(sf::Time deltaTime);
        void render(sf::RenderWindow *window);

};

#endif

