#pragma once
#include "SFML/Graphics.hpp"
#include "Const.h"
class Starship
{
public:
	Starship();
	void OnEvent(sf::Event event);
	void Update();
	sf::ConvexShape Ship() { return _ship; }

private:
	sf::ConvexShape _ship;
	sf::Texture _shipTexture;
	sf::Vector2f _speed;
	sf::Vector2f _acceleration;
	float _rotateAngle;

};

