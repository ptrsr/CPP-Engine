#include "SFML\Graphics.hpp"
#include "GameObject.h"

class Engine
{
private:
	//singleton
	static Engine* game;
	Engine();
	//private members
	std::vector<GameObject*> children;
	sf::RenderWindow* window;

protected: //todo: split engine from game
	void start();

public:
	//singleton functions
	static Engine& get();
	Engine(Engine const&) = delete;
	void operator=(Engine const&) = delete;

	//game functions
	void setWindow(sf::RenderWindow*);
	void gameLoop();
	void addChild(GameObject*);

};