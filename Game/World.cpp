#include "World.h"
#include <iostream>

GameObject* World::world;

GameObject& World::Get()
{
	if (world == nullptr)
	{
		std::cout << "creating new world" << std::endl;
		world = new World();
	}
	return *world;
}

void World::AddChild(GameObject* child)
{
	World::Get().AddChild(child);
}

void World::RemoveChild(GameObject* child)
{
	World::Get().RemoveChild(child);
}

World::World()
{
	this->name = "World";
}
