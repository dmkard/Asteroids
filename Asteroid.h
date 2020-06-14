#pragma once
#include "SFML/Graphics.hpp"

class Asteroid
{
public:
	Asteroid();
	void Update();
	sf::ConvexShape Shape() { return _asteroid; }
	sf::Vector2f Location() { return _asteroid.getPosition(); }

private:
	sf::ConvexShape _asteroid;
	float _scale;

};

