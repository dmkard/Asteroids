#include "Game.h"
#include <Windows.h>


Game::Game(const int& fps) :
	_framesPerSecond(fps),
	_ship()
{
	_window.create({ 1200, 800, 32 }, "Asteroids");
	FreeConsole();
}
Game::~Game()
{
	_window.close();
}
void Game::Run()
{
	sf::Clock clock;
	sf::Time endFrameTime;
	_running = true;
	while (_running)
	{	
		clock.restart();
		HandleInput();
		Update();
		Render();

		endFrameTime = clock.getElapsedTime();
		if (endFrameTime.asMicroseconds() < _frameTime)
			sf::sleep(sf::milliseconds(_frameTime - endFrameTime.asMilliseconds()));
	}
}

void Game::HandleInput()
{
	sf::Event event;
	while (_window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			_running = false;
			break;

		case sf::Event::KeyPressed:
		{
			switch (event.key.code)
			{

			}
		}
		};

	}
}
void Game::Update()
{

}
void Game::Render()
{
	_window.clear(sf::Color::Black);
	
	_window.draw(_ship.Ship());
	_window.display();
}