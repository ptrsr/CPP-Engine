#ifndef IMAGECACHE
#define IMAGECACHE

#include <map>
#include <SFML\Graphics.hpp>
#include "GameObject.h"

class ImageCache
{
public:
	static sf::Texture* Push(std::string);
	static ImageCache & Get();

	ImageCache(ImageCache const&) = delete;
	void operator=(ImageCache const&) = delete;

private:
	ImageCache();
	static ImageCache * cache;

	std::map<std::string, sf::Texture> * images;
};



#endif
