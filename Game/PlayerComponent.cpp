#include "PlayerComponent.h"
#include "SFML\Graphics.hpp"

PlayerComponent::PlayerComponent()
{
	aimSpeed = 1;

	
}

void PlayerComponent::move()
{
	sf::Vector2f moveVec;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		moveVec += sf::Vector2f(0, -aimSpeed);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		moveVec += sf::Vector2f(0, aimSpeed);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		moveVec += sf::Vector2f(0, aimSpeed);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		moveVec += sf::Vector2f(0, aimSpeed);

}