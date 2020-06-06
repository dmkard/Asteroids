
#include "Starship.h"
#include <iostream>

Starship::Starship():
	_speed({ .0f, .0f })
{
	if (!_shipTexture.loadFromFile("model.png"))
		exit(EXIT_FAILURE);
	sf::Vector2f _shipSize = { static_cast <float> (_shipTexture.getSize().x), static_cast <float> (_shipTexture.getSize().y) };
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
	//_ship.setFillColor(sf::Color::Green);

	_ship.setTexture(&_shipTexture);
}


void Starship::Update()
{
	sf::Vector2f pos = _ship.getPosition();
	if (pos.x > WNDWIDTH)
		_ship.setPosition({ 0, pos.y });
	else if (pos.x  < 0)
		_ship.setPosition({ WNDWIDTH, pos.y });

	if (pos.y > WNDHEIGHT)
		_ship.setPosition({ pos.x, 0 });
	else if (pos.y < 0)
		_ship.setPosition({ pos.x, WNDHEIGHT });

	float rot = _ship.getRotation();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		std::cout << rot << std::endl;
		_speed.x += sin(rot * M_PI / 180) * 0.2;
		_speed.y -= cos(rot * M_PI / 180) * 0.2;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		_speed.x -= sin(rot * M_PI / 180) * 0.2;
		_speed.y += cos(rot * M_PI / 180) * 0.2;
	}
	else
	{
		if (_speed.x != 0)
		{
			if (_speed.x < 0.01 && _speed.x > -0.01)
				_speed.x = 0;
			_speed.x *= 0.95;
		}
		if (_speed.y != 0)
		{
			if (_speed.y < 0.01 && _speed.y > -0.01)
				_speed.y = 0;
			_speed.y *= 0.95;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		_ship.rotate(4);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		_ship.rotate(-4);

	if (_speed.x > MAXSPEED)
		_speed.x = MAXSPEED;
	else if(_speed.x < -MAXSPEED)
		_speed.x = -MAXSPEED;
	if (_speed.y > MAXSPEED)
		_speed.y = MAXSPEED;
	else if (_speed.y < -MAXSPEED)
		_speed.y = -MAXSPEED;

	_ship.move({ _speed.x, _speed.y });
}
