#ifndef GAMEOBJECT
#define GAMEOBJECT

#include <typeindex>
#include <memory>
#include <vector>
#include <map>
#include <string>

#include "Component.h"
#include "SFML\Graphics\Transformable.hpp"

class GameObject : public sf::Transformable
{
private:

	sf::Transform globalTransform;

	GameObject* parent;
	std::map<std::type_index, Component*> components;

protected:
	static GameObject * game;

public:
	std::string name;
	std::vector<GameObject*> children;

	GameObject(std::string name = "New GameObject", sf::Vector2f pos = sf::Vector2f());
	~GameObject();
	virtual void Update();

	sf::Transform getGlobalTransform();

	void AddChild(GameObject *);
	void RemoveChild(GameObject *);

	void AddComponent(Component*);

	template <typename T>
	T * GetComponent()
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
	bool HasComponent()
	{
		if (components.count(std::type_index(typeid(T))) != 0)
			return true;
		else
			return false;
	}
};

#endif