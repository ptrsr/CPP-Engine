#include "SFML\Graphics.hpp"
#include "Engine.h"

//GAME SETTINGS =============================
int GAMEHEIGHT = 720;
int GAMEWIDTH = 1280;

auto GAMENAME = "Desert Storm";
//===========================================

int main()
{
	sf::RenderWindow window(sf::VideoMode(GAMEWIDTH, GAMEHEIGHT), GAMENAME);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);

	Engine::get().setWindow(&window);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		Engine::get().gameLoop();
	}

	return 0;
}