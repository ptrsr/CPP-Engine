#ifndef SPRITECOMPONENT
#define SPRITECOMPONENT
#include "SFML\Graphics.hpp"
#include "Component.h"
#include "Enums.h"
class SpriteComponent : public Component
{
public:
	//Constructor
	SpriteComponent(sf::Texture* = nullptr, unsigned int cols = 1, unsigned int rows = 1, Enums::Origin origin = Enums::Origin::top_left);
	SpriteComponent(std::string fileName, unsigned int cols = 1, unsigned int rows = 1, Enums::Origin origin = Enums::Origin::top_left);
	//Functions
	void SetSprite(sf::Texture*, unsigned int cols = 1, unsigned int rows = 1, Enums::Origin origin = Enums::Origin::top_left);
	void SetSprite(std::string fileName, unsigned int cols = 1, unsigned int rows = 1, Enums::Origin origin = Enums::Origin::top_left);
	void SetOrigin(Enums::Origin origin = Enums::Origin::top_left);

	void SetAnim(int, int);
	void SetFrame(int);
	sf::Sprite* GetSprite();

	void Update() {};

private:
	//Variables
	sf::Texture * texture;
	sf::Sprite sprite;
	sf::Vector2i spriteSize;
	
	unsigned int cols;
	unsigned int rows;
};

#endif