#include "Launcher.h"
#include "SpriteComponent.h"
#include "Engine.h"

Launcher::Launcher(sf::Vector2u)
{
	Engine::get().addChild(this);

	SpriteComponent * sprite = new SpriteComponent("Circle.png");
	addComponent(sprite);


}
