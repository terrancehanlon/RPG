// #pragma once
#ifndef IMPORTS_H
#define IMPORTS_H

// Lua is written in C, so compiler needs to know how to link its libraries
// /usr/include/lua5.3
extern "C" {
# include "/usr/include/lua5.3/lua.h"
# include "/usr/include/lua5.3/lauxlib.h"
# include "/usr/include/lua5.3/lualib.h"
}

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

#include "AnimatedSprite.hpp"
#include "Animation.hpp"

// #include "LuaBridge/Source/LuaBridge/LuaBridge.h"

// #include "Lib/LuaBridge/Source/LuaBridge/LuaBridge.h"

class Imports {

};

#endif