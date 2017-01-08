#include "SpriteComponent.h"
#include <iostream>

SpriteComponent::SpriteComponent(sf::Texture * texture, unsigned int cols, unsigned int rows, Enums::Origin origin)
{ 
	if (texture != nullptr)
		SetSprite(texture, cols, rows, origin);
}

SpriteComponent::SpriteComponent(std::string fileName, unsigned int cols, unsigned int rows, Enums::Origin origin)
{
	SetSprite(fileName, cols, rows, origin);
}

void SpriteComponent::SetSprite(sf::Texture * texture, unsigned int cols, unsigned int rows, Enums::Origin origin)
{
	this->texture = texture;
	sprite.setTexture(*texture);

	SetAnim(cols, rows);
	SetOrigin(origin);
}

void SpriteComponent::SetSprite(std::string fileName, unsigned int cols, unsigned int rows, Enums::Origin origin)
{
	texture->loadFromFile("sprites/" + fileName);
	sprite.setTexture(*texture);

	SetAnim(cols, rows);
	SetOrigin(origin);
}

void SpriteComponent::SetAnim(int x, int y)
{
	this->cols = x;
	this->rows = y;

	if (x == 1 && y == 1)
		spriteSize = (sf::Vector2i)texture->getSize();
	else
	{
		sf::Vector2u tempSize = texture->getSize();
		spriteSize = sf::Vector2i(tempSize.x / cols, tempSize.y / rows);
		SetFrame(1);
	}
}

void SpriteComponent::SetFrame(int frame)
{
	sf::Vector2i rectPos = sf::Vector2i(((frame % cols) % cols) * spriteSize.x, ((frame / cols) % rows) * spriteSize.y);
	sprite.setTextureRect(sf::IntRect(rectPos, spriteSize));
}

void SpriteComponent::SetOrigin(Enums::Origin origin)
{
	switch (origin)
	{
	case Enums::Origin::top_left:
		sprite.setOrigin(0, 0);
		break;

	case Enums::Origin::top_right:
		sprite.setOrigin((float)spriteSize.x, 0);
		break;

	case Enums::Origin::center:
		sprite.setOrigin((float)spriteSize.x / 2, (float)spriteSize.y / 2);
		break;

	case Enums::Origin::bottom_left:
		sprite.setOrigin(0, (float)spriteSize.y);
		break;

	case Enums::Origin::bottom_right:
		sprite.setOrigin((float)spriteSize.x, (float)spriteSize.y);
		break;
	}
}

sf::Sprite* SpriteComponent::GetSprite()
{
	return &sprite;
}

