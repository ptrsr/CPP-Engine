#include "Engine.h"
#include "GameObject.h"
#include "SpriteComponent.h"
#include "World.h"
#include "InputHandler.h"

#include <vector>
#include <iostream>


Engine::Engine(int windowWidth, int windowHeight, std::string gameName, bool vSync) 
{ 
	window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), gameName, sf::Style::Default, sf::ContextSettings(24, 8, 0, 3, 3));
	window->setVerticalSyncEnabled(vSync);

	InputHandler::SetWindow(window);
}

void Engine::Update()
{
	GameObject & world = World::Get();

	world.Update();

	for each (GameObject* obj in world.children)
	{
		if (obj->HasComponent<SpriteComponent>())
			window->draw(*obj->GetComponent<SpriteComponent>()->GetSprite(), obj->getGlobalTransform());
	}
}

void Engine::Run() 
{
	while (window->isOpen())
	{
		InputHandler::Update();

		if (InputHandler::close)
			window->close();

		window->clear();
		Update();
		window->display();
	}
	
}