#pragma once
#include "SFML/Graphics.hpp"
#include "Starship.h"

class Game
{
public:
	Game(const int& fps = 60);
	~Game();
	void Run();
	void HandleInput();
	void Update();
	void Render();
private:
	sf::RenderWindow _window;
	Starship _ship;
	bool _running{ false };
	int _framesPerSecond{ 60 };
	int _frameTime{ 1000 / _framesPerSecond };

};

