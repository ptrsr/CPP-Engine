#include "GameObject.h"
#include <iostream>
#include <algorithm>

GameObject::GameObject(std::string name, sf::Vector2f spawnPos)
{
	this->name = name;
	setPosition(spawnPos);
}

sf::Transform GameObject::getGlobalTransform()
{
	if (parent != nullptr) {
		return getTransform() * parent->getGlobalTransform();
	}
	else
		return getTransform();
}

void GameObject::AddChild(GameObject * child) 
{
	children.push_back(child);
	child->parent = this;
}

void GameObject::RemoveChild(GameObject * child) 
{
	children.erase(std::remove(children.begin(), children.end(), child), children.end());
	child->parent = nullptr;
}

void GameObject::AddComponent(Component* component)
{
	component->parent = this;
	components[std::type_index(typeid(*component))] = component;
}

void GameObject::Update() 
{
	for (auto const& comp : components) 
		((Component*)comp.second)->Update();

	for each (GameObject* child in children)
		child->Update();
}

GameObject::~GameObject()
{
	if (parent != nullptr)
		this->parent->RemoveChild(this);

	for (std::map<std::type_index, Component*>::iterator itr = components.begin(); itr != components.end(); ++itr)
	{
		if (itr->second != nullptr)
			delete itr->second;
	}
	components.clear();
}

