#pragma once
#include "SFML/Graphics.hpp"
class Starship
{
public:
	Starship();
	sf::ConvexShape Ship() { return _ship; }
private:
	sf::ConvexShape _ship;
	sf::Texture _shipTexture;

};

