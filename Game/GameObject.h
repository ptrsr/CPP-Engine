#ifndef GAMEOBJECT
#define GAMEOBJECT

#include <typeindex>
#include <memory>
#include <vector>
#include <map>

#include "Component.h"
#include "SFML\Graphics\Transformable.hpp"

class GameObject : public sf::Transformable
{
private:

	sf::Transform globalTransform;

	GameObject* parent;
	std::map<std::type_index, Component * > components;

protected:
	static GameObject * game;

public:
	std::vector<GameObject*> children;

	GameObject();
	GameObject(sf::Vector2f);

	virtual void update();

	sf::Transform getGlobalTransform();

	void addChild(GameObject *);
	void removeChild(GameObject *);

	void addComponent(Component*);

	template <typename T>
	T * getComponent()
	{
		std::type_index index(typeid(T));

		if (components.count(index) != 0)
		{
			return static_cast<T*>(components[index]);
		}
		else
		{
			return nullptr;
		}
	}

	template <typename T>
	bool hasComponent()
	{
		if (components.count(std::type_index(typeid(T))) != 0)
			return true;
		else
			return false;
	}
};

#endif