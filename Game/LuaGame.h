#ifndef LUAGAME
#define LUAGAME

#include "Engine.h"
#include "LuaParser.hpp"

class LuaGame : public Engine
{
private:

public:
	LuaGame(int windowWidth = 1280, int windowHeight = 720, std::string gameName = "Lua Game", bool vSync = true);
};

#endif