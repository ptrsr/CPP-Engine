#ifndef COMPONENT
#define COMPONENT

#include <map>
#include <typeindex>

#include "SFML\Graphics\Transformable.hpp"

class Component
{
public:
	virtual void update() { };
	sf::Transformable & parent;
};

#endif