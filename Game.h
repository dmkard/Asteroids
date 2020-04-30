#pragma once
#include "SFML/Graphics.hpp"
#include "Starship.h"
#include "Const.h"

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

};

