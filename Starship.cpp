#include "Starship.h"
#include <iostream>

Starship::Starship():
	_speed({ .0f, .0f }),
	_acceleration({ .0f, .0f }),
	_rotateAngle(0)
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
	_ship.setPosition(WNDWIDTH / 2, WNDHEIGHT / 2);
	_ship.setTexture(&_shipTexture);
}

void Starship::OnEvent(sf::Event event)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		_speed.y += -0.1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		_speed.y += 0.1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		_speed.x += 0.1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		_speed.x += -0.1;
}

void Starship::Update()
{
	if (_ship.getPosition().x > WNDWIDTH)
		_ship.setPosition({ 0, _ship.getPosition().y });
	else if (_ship.getPosition().x  < 0)
		_ship.setPosition({ WNDWIDTH, _ship.getPosition().y });

	if (_ship.getPosition().y > WNDHEIGHT)
		_ship.setPosition({ _ship.getPosition().x, 0 });
	else if (_ship.getPosition().y < 0)
		_ship.setPosition({ _ship.getPosition().x, WNDHEIGHT });


	sf::Vector2f position = _ship.getPosition();
	position += {_speed.x, _speed.y};
	_ship.setPosition(position);
}
