#include <iostream>

#include "LuaGame.h"
#include "World.h"

LuaGame::LuaGame(int windowWidth, int windowHeight, std::string gameName, bool vSync) 
	: Engine(windowWidth, windowHeight, gameName, vSync) 
{
	Component * parser = new LuaParser();
	World::Get().AddComponent(parser);
}
