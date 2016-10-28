#include "Engine.h"
#include "GameObject.h"
#include "SpriteComponent.h"
#include <vector>
#include <iostream>

Engine* Engine::game;

Engine::Engine() { };

void Engine::start()
{
	
}

void Engine::gameLoop() 
{
	window->clear();

	for each (GameObject* obj in children)
	{
		obj->update();

		if (obj->hasComponent<SpriteComponent>())
		{
			window->draw(obj->getComponent<SpriteComponent>()->GetSprite(), obj->getGlobalTransform());
		}
	}

	window->display();
}

void Engine::addChild(GameObject* child)
{
	this->children.push_back(child);

}

void Engine::setWindow(sf::RenderWindow* window)
{
	this->window = window;
}

Engine& Engine::get()
{
	if (game == nullptr) 
	{
		game = new Engine();
		game->start();
	}
	return *game;
}