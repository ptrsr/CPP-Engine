#include "SFML\Graphics.hpp"

#include "Component.h"
#include "Enums.h"

class RectangleComponent : public Component
{
public:
	RectangleComponent(sf::Vector2f, Enums::Origin origin = Enums::Origin::top_left);

	void SetOrigin(Enums::Origin origin = Enums::center);

private:
	sf::RectangleShape * rectangle;
};