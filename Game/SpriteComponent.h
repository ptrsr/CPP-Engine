#ifndef SPRITECOMPONENT
#define SPRITECOMPONENT

#include "SFML\Graphics.hpp"
#include "Component.h"

class SpriteComponent : public Component
{
public:
	//enum
	enum Origin { top_left, top_right, center, bottom_left, bottom_right };

	//Constructor
	SpriteComponent(std::string fileName, unsigned int cols = 1, unsigned int rows = 1, Origin origin = Origin::top_left);

	//Functions
	void setSprite(std::string fileName, unsigned int cols = 1, unsigned int rows = 1, Origin origin = Origin::top_left);
	void setOrigin(Origin = Origin::top_left);
	void setFrame(int);
	sf::Sprite& GetSprite();
	//void Update();

private:
	//Variables
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2i spriteSize;
	
	unsigned int cols;
	unsigned int rows;
};

#endif