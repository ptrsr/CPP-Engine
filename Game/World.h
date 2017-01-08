#ifndef WORLD
#define WORLD

#include "GameObject.h"

class World : public GameObject
{
public:
	static GameObject& Get();
	static void AddChild(GameObject*);
	static void RemoveChild(GameObject*);

private:
	World();
	static GameObject * world;
};

#endif // !WORLD
