#include "Bullet.h"
#include "Const.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>

int Bullet::currentID = 0;

Bullet::Bullet(sf::Vector2f loc, int dir): _direction(dir)
{
	_id = currentID++;
	_shape.setRadius(6.f);
	_shape.setOrigin({ 3., 3. });
	_shape.setPosition({ loc.x - 3, loc.y - 3 });
	_shape.setFillColor(sf::Color::White);
}

void Bullet::Update()
{
	_shape.move({ 15 * sin(_direction * static_cast <float>(M_PI) / 180),  
					-15 * cos(_direction * static_cast <float>(M_PI) / 180) });


}

