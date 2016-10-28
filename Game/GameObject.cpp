#include "GameObject.h"
#include <iostream>

GameObject::GameObject() { };

GameObject::GameObject(sf::Vector2f spawnPos)
{
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

void GameObject::addChild(GameObject * other) 
{
	children.push_back(other);
	other->parent = this;
}

void GameObject::removeChild(GameObject * other) 
{
	children.erase(std::remove(children.begin(), children.end(), other), children.end());
	other->parent = nullptr;
}

void GameObject::addComponent(Component* component)
{
	component->parent = this;

	components[std::type_index(typeid(*component))] = component;
}

void GameObject::update() 
{
	for (auto const& comp : components) 
	{
		((Component*)comp.second)->update();
	}
}

