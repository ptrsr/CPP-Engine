#include "SFML\Graphics.hpp"
#include "LuaGame.h"

int main()
{
	Engine * game = new LuaGame();
	game->Run();

	//delete game;
	return 0;
}