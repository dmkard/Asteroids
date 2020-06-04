#include "Bullet.h"
#include "Const.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>

Bullet::Bullet(sf::Vector2f loc, int dir): _direction(dir)
{
	_shape.setRadius(6.f);
	_shape.setOrigin({ 3., 3. });
	_shape.setPosition({ loc.x - 3, loc.y - 3 });
	_shape.setFillColor(sf::Color::White);
	std::cout << "Location: " << loc.x << " " << loc.y << std::endl;
}

void Bullet::Update()
{
	_shape.move({ 10 * sin(_direction * static_cast <float>(M_PI) / 180),  -10 * cos(_direction * static_cast <float>(M_PI) / 180) });
	/*if (_shape.getPosition().x + 6 < 0 ||
		_shape.getPosition().x - 6 > WNDWIDTH ||
		_shape.getPosition().y + 6 < 0 ||
		_shape.getPosition().y -6 > WNDHEIGHT)*/

}

sf::CircleShape Bullet::Shape() { return _shape; }