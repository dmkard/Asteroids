#pragma once
#include "SFML/Graphics.hpp"
#include <list>
#include "Starship.h"
#include "Const.h"
#include "Bullet.h"


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
	bool _running{ false };
	int _framesPerSecond;
	int _frameTime;
	std::list<Bullet> _bullets;

};

