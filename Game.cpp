#include "Game.h"
#include <Windows.h>
#include <iostream>
#include <random>
#include <math.h>

Game::Game():
	_framesPerSecond(FPS),
	_ship(),
	_interface()
{
	_score = 0;
	_frameTime = 1000 / FPS;
	_window.create({ WNDWIDTH, WNDHEIGHT, 32 }, TITLE);
	_window.setKeyRepeatEnabled(true);
}
Game::~Game()
{
	_window.close();
}
void Game::Run()
{
	sf::Clock clock; //count time of frame
	sf::Time endFrameTime;
	_running = true;
	while (_running)
	{	
		clock.restart(); //clock equels 0 at this point

		HandleInput();
		Update();
		Render();
		endFrameTime = clock.getElapsedTime(); //get elated time from beginning of frame
		if (endFrameTime.asMilliseconds() < _frameTime)
			sf::sleep(sf::milliseconds(_frameTime - endFrameTime.asMilliseconds()));  
	}
}

//this function handle close event
void Game::HandleInput()
{
	static sf::Clock clock; 
	sf::Time time = clock.getElapsedTime();
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
	if (time.asMilliseconds() > 200)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			_bullets.push_back(Bullet(_ship.Ship().getPosition(), _ship.Ship().getRotation()));
			clock.restart();
		}
	}
}
void Game::Update()
{
	_ship.Update();
	static sf::Clock clock;
	sf::Time time = clock.getElapsedTime();

	std::list<Bullet>::iterator itBull = _bullets.begin();
	while ( itBull != _bullets.end())
	{
		if ((*itBull).Location().x + 6 < 0 ||
			(*itBull).Location().x - 6 > WNDWIDTH ||
			(*itBull).Location().y + 6 < 0 ||
			(*itBull).Location().y - 6 > WNDHEIGHT)
		{
			_bullets.erase(itBull++);
		}
		else
		{
			(*itBull).Update();
			itBull++;
		}
	}

	if (time.asMilliseconds() > 400)
	{
		_asteroids.push_back(Asteroid());
		clock.restart();
	}

	std::list<Asteroid>::iterator itAst = _asteroids.begin();
	while (itAst != _asteroids.end())
	{
		if (
			(*itAst).Location().x + 80 < 0 ||
			(*itAst).Location().x - 80 > WNDWIDTH ||
			(*itAst).Location().y + 80 < 0 ||
			(*itAst).Location().y - 80 > WNDHEIGHT
			)
		{
			_asteroids.erase(itAst++);
		}
		else
		{
			(*itAst).Update();
			itAst++;
		}
	}

	bool colision;
	itBull = _bullets.begin();
	while (itBull != _bullets.end())
	{
		colision = false;
		itAst = _asteroids.begin();
		while (itAst != _asteroids.end())
		{
			double distance = sqrt(pow((*itAst).Location().x - (*itBull).Location().x, 2) 
									+ pow((*itAst).Location().y - (*itBull).Location().y, 2));

			if ((*itAst).Radius() > distance)
			{
				_score +=  (2 - (*itAst).Radius() / 30) * 100;
				_asteroids.erase(itAst++);
				_bullets.erase(itBull++);
				colision = true;
				break;
			}
			else
			{
				itAst++;
			}
		}
		if (!colision)
			itBull++;
	}
	_interface.Update(_score);
}

void Game::Render()
{
	_window.clear(sf::Color::Black);
	_window.draw(_ship.Ship());
	for (auto& bullet : _bullets)
		_window.draw(bullet.Shape());

	for (auto& asteroid : _asteroids)
		_window.draw(asteroid.Shape());
	_window.draw(_interface);
	_window.display();
}