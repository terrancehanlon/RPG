#ifndef ENTITY_H
#define ENTITY_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

#include "../Lib/AnimatedSprite.hpp"
#include "../Lib/Animation.hpp"

#include "../States/State.h"


// #include <vector>
#include <stack>

class Entity
{
    private:



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

