#pragma once
#include "SFML/Graphics.hpp"
class Game
{
public:
	Game(const int& fps);
	~Game();
	void Run();
	void HandleInput();
	void Update();
	void Render();
private:
	sf::RenderWindow _window;
	bool _running{ false };
	int _framesPerSecond{ 60 };
	int _frameTime{ 1000 / _framesPerSecond };

};

