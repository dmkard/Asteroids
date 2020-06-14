#pragma once
#include "SFML/Graphics.hpp"
#include <list>
#include "Starship.h"
#include "Const.h"
#include "Bullet.h"
#include "Asteroid.h"
#include "Interface.h"


/*
	Class Game represent game window and all events which take place in game
*/
class Game
{
public:
	Game();
	~Game();
	void Run();
	void HandleInput();
	void Update();
	void Render();
private:
	sf::RenderWindow _window;
	Starship _ship;
	Interface _interface;
	bool _running{ false };
	int _framesPerSecond;
	int _frameTime;
	int _score;
	std::list<Bullet> _bullets;
	std::list<Asteroid> _asteroids;


};

