#include "RectangleComponent.h"

RectangleComponent::RectangleComponent(sf::Vector2f size, Enums::Origin origin)
{
	rectangle = new sf::RectangleShape(size);
	SetOrigin(origin);
}

void RectangleComponent::SetOrigin(Enums::Origin origin)
{
	switch (origin)
	{
	case Enums::Origin::top_left:
		rectangle->setOrigin(0, 0);
		break;

	case Enums::Origin::top_right:
		rectangle->setOrigin((float)rectangle->getSize().x, 0);
		break;

	case Enums::Origin::center:
		rectangle->setOrigin((float)rectangle->getSize().x / 2, (float)rectangle->getSize().y / 2);
		break;

	case Enums::Origin::bottom_left:
		rectangle->setOrigin(0, (float)rectangle->getSize().y);
		break;

	case Enums::Origin::bottom_right:
		rectangle->setOrigin((float)rectangle->getSize().x, (float)rectangle->getSize().y);
		break;
	}
}
