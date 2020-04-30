#include "Starship.h"

Starship::Starship()
{
	if (!_shipTexture.loadFromFile("model.png"))
		exit(EXIT_FAILURE);
	auto _shipSize = _shipTexture.getSize();
	//m_planeTexture.setSmooth(true);
	_ship.setPointCount(7);
	_ship.setPoint(0, sf::Vector2f(_shipSize.x, _shipSize.y));
	_ship.setPoint(1, sf::Vector2f(0, _shipSize.y));
	_ship.setPoint(2, sf::Vector2f(0, _shipSize.y - 20));
	_ship.setPoint(3, sf::Vector2f(_shipSize.x / 2 - 20, 0));
	_ship.setPoint(4, sf::Vector2f(_shipSize.x / 2, 0));
	_ship.setPoint(5, sf::Vector2f(_shipSize.x / 2 + 20, 0));
	_ship.setPoint(6, sf::Vector2f(_shipSize.x, _shipSize.y - 20));
	_ship.setOrigin(sf::Vector2f(_shipSize.x / 2, _shipSize.y / 2));
	_ship.setPosition(_shipSize.x / 2, _shipSize.y / 2);
	_ship.setTexture(&_shipTexture);
}
