#include <random>
#define _USE_MATH_DEFINES
#include <math.h>
#include "Asteroid.h"
#include "Const.h"
#include <iostream>

Asteroid::Asteroid()
{
	_asteroid.setPointCount(8);
	std::random_device rand;
	std::uniform_int_distribution<int> intDest(-9, 9);
	std::uniform_int_distribution<int> scaleIntDest(5, 15);
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

	_asteroid.scale(1 * _scale, 1 * _scale);
	_asteroid.setPosition(WNDWIDTH / 2, WNDHEIGHT / 2);
	_asteroid.setOutlineThickness(2);
	_asteroid.setFillColor(sf::Color::Transparent);

	//rotation and spawn section
	int angle;
	std::uniform_int_distribution<int> intDestSide(0, 3); // generate side of spawning
	std::uniform_int_distribution<int> intDestWidth(0, WNDWIDTH);
	std::uniform_int_distribution<int> intDestHeight(0, WNDHEIGHT);
	std::uniform_int_distribution<int> intDestAngle(0, 180);
	angle = intDestAngle(rand);
	switch (intDestSide(rand))
	{
	case 0: //west side
		_asteroid.setPosition(-70, intDestHeight(rand));
		_asteroid.rotate(angle); 	//in case angle should be between 0-180
		break;
	case 1: //south side
		_asteroid.setPosition(intDestWidth(rand), WNDHEIGHT + 70);
		angle += 270;
		if (angle > 360)//in case angle should be between 270-360 or 0-90
			angle /= 90;
		_asteroid.rotate(angle);
		break;
	case 2: //east side
		_asteroid.setPosition(WNDWIDTH + 70, intDestHeight(rand));
		angle += 180; //in case angle should be between 180-360
		_asteroid.rotate(angle);
		break;
	case 3: //north side
		_asteroid.setPosition(intDestWidth(rand), -70);
		angle += 90; //in case angle should be between 90-270
		_asteroid.rotate(angle);
		break;
	}
}

void Asteroid::Update()
{
	_asteroid.move({ 5 / _scale * sin(_asteroid.getRotation() * static_cast <float>(M_PI) / 180), 
					-5 / _scale * cos(_asteroid.getRotation() * static_cast <float>(M_PI) / 180)		});
}
