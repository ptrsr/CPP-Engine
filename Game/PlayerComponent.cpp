#include "PlayerComponent.h"


PlayerComponent::PlayerComponent()
{
	aimSpeed = 1;

	parent.move(1, 0);
}