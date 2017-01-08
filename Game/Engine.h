#include "SFML\Graphics.hpp"
#include "GameObject.h"
#include <string>

class Engine
{
private:
	sf::RenderWindow* window;

protected:
	void Update();

public:
	Engine(int windowWidth, int windowHeight, std::string gameName, bool vSync);

	void Run();
};