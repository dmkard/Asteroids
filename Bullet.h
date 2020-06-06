#pragma once
#include "SFML/Graphics.hpp"

class Bullet
{
public:
	Bullet(sf::Vector2f loc, int dir);
	void Update();
	static int currentID;
	bool operator == (const Bullet& b) const { return  _id == b._id; }
	bool operator != (const Bullet& b) const { return !operator==(b); }
	sf::CircleShape Shape() { return _shape; }
	sf::Vector2f Location() { return _shape.getPosition(); }
private:
	sf::CircleShape _shape;
	int _direction; //in degrees
	int _id;

};

