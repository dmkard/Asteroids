#include <random>
#include "Asteroid.h"
#include "Const.h"

Asteroid::Asteroid()
{
	_asteroid.setPointCount(8);
	std::random_device rand;
	std::uniform_int_distribution<int> intDest(-9, 9);
	std::uniform_int_distribution<int> scaleIntDest(-5, 5);
	_asteroid.setPoint(0, sf::Vector2f(20 + intDest(rand), 0 + intDest(rand)));
	_asteroid.setPoint(1, sf::Vector2f(40 + intDest(rand), 0 + intDest(rand)));
	_asteroid.setPoint(2, sf::Vector2f(60 + intDest(rand), 20 + intDest(rand)));
	_asteroid.setPoint(3, sf::Vector2f(60 + intDest(rand), 40 + intDest(rand)));
	_asteroid.setPoint(4, sf::Vector2f(40 + intDest(rand), 60 + intDest(rand)));
	_asteroid.setPoint(5, sf::Vector2f(20 + intDest(rand), 60 + intDest(rand)));
	_asteroid.setPoint(6, sf::Vector2f(0 + intDest(rand), 40 + intDest(rand)));
	_asteroid.setPoint(7, sf::Vector2f(0 + intDest(rand), 20 + intDest(rand)));
	_asteroid.setOrigin(sf::Vector2f(30,30));
	_scale = scaleIntDest(rand) / 10.;
	_asteroid.scale(1 + _scale, 1 + _scale);
	_asteroid.setPosition(WNDWIDTH / 2, WNDHEIGHT / 2);
	_asteroid.setOutlineThickness(2);
	_asteroid.setFillColor(sf::Color::Transparent);
}
