
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


	float rot = _ship.getRotation();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		std::cout << rot << std::endl;
		_speed.x += sin(rot * M_PI / 180);
		_speed.y -= cos(rot * M_PI / 180);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		_speed.x -= sin(rot * M_PI / 180);
		_speed.y += cos(rot * M_PI / 180);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		_ship.rotate(10);


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		_ship.rotate(-10);

	_ship.move({ _speed.x, _speed.y });
	

}
