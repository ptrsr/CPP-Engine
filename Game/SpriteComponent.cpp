#include "SpriteComponent.h"
#include <iostream>

SpriteComponent::SpriteComponent(std::string fileName, unsigned int cols, unsigned int rows, Origin origin)
{
	setSprite(fileName, cols, rows, origin);
}

void SpriteComponent::setSprite(std::string fileName, unsigned int cols, unsigned int rows, Origin origin)
{
	texture.loadFromFile("sprites/" + fileName);
	
	this->cols = cols;
	this->rows = rows;

	sprite.setTexture(texture);

	if (cols == 1 && rows == 1)
		spriteSize = (sf::Vector2i)texture.getSize();
	else
	{
		sf::Vector2u tempSize = texture.getSize();
		spriteSize = sf::Vector2i(tempSize.x / cols, tempSize.y / rows);
		setFrame(1);
	}

	setOrigin(origin);
}

void SpriteComponent::setFrame(int frame)
{
	sf::Vector2i rectPos = sf::Vector2i(((frame % cols) % cols) * spriteSize.x, ((frame / cols) % rows) * spriteSize.y);
	sprite.setTextureRect(sf::IntRect(rectPos, spriteSize));
}

void SpriteComponent::setOrigin(Origin origin)
{
	switch (origin)
	{
	case Origin::top_left:
		sprite.setOrigin(0, 0);
		break;

	case Origin::top_right:
		sprite.setOrigin((float)spriteSize.x, 0);
		break;

	case Origin::center:
		sprite.setOrigin((float)spriteSize.x / 2, (float)spriteSize.y / 2);
		break;

	case Origin::bottom_left:
		sprite.setOrigin(0, (float)spriteSize.y);
		break;

	case Origin::bottom_right:
		sprite.setOrigin((float)spriteSize.x, (float)spriteSize.y);
		break;
	}
}

sf::Sprite& SpriteComponent::GetSprite()
{
	return sprite;
}

