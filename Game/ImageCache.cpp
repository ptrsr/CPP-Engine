#include "ImageCache.h"
#include "World.h"
#include "SpriteComponent.h"
#include <iostream>

ImageCache* ImageCache::cache;

ImageCache::ImageCache()
{
	images = new std::map<std::string, sf::Texture>;
}

ImageCache& ImageCache::Get()
{
	if (cache == nullptr)
		cache = new ImageCache();

	return *cache;
}

sf::Texture* ImageCache::Push(std::string fileName)
{
	sf::Texture* image = nullptr;
	std::map<std::string, sf::Texture> * images = ImageCache::Get().images;

	if (images->count(fileName) != 0)
		image = &(*images)[fileName];
	else
	{
		sf::Texture temp;
		temp.loadFromFile("sprites/" + fileName);
		image = &temp;
		(*images)[fileName] = temp;
	}

	return image;
}