#include "Game.h"
#include <Windows.h>
#include <iostream>

Game::Game():
	_framesPerSecond(FPS),
	_ship()
{
	_frameTime = 1000 / FPS;
	_window.create({ WNDWIDTH, WNDHEIGHT, 32 }, TITLE);
	_window.setKeyRepeatEnabled(true);
	//FreeConsole();
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
		if (endFrameTime.asMilliseconds() < _frameTime)
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

		default:
			break;
		};
	}
}
void Game::Update()
{
	_ship.Update();
}
void Game::Render()
{
	_window.clear(sf::Color::Black);
	_window.draw(_ship.Ship());
	_window.display();
}