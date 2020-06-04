#pragma once
#include "SFML/Graphics.hpp"

class Bullet
{
public:
	Bullet(sf::Vector2f loc, int dir);
	void Update();
	sf::CircleShape Shape();
private:
	sf::CircleShape _shape;
	int _direction; //in degrees

};

