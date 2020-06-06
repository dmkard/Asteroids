#pragma once
#include "SFML/Graphics.hpp"
#include "Const.h"
#define _USE_MATH_DEFINES
#include <math.h>

class Starship
{
public:
	Starship();
	void Update();
	sf::ConvexShape Ship() { return _ship; }

private:
	sf::ConvexShape _ship;
	sf::Texture _shipTexture;
	sf::Vector2f _speed;
};

