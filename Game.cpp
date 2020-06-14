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

	std::list<Bullet>::iterator it = _bullets.begin();
	while ( it != _bullets.end())
	{
		if ((*it).Location().x + 6 < 0 ||
			(*it).Location().x - 6 > WNDWIDTH ||
			(*it).Location().y + 6 < 0 ||
			(*it).Location().y - 6 > WNDHEIGHT)
		{
			_bullets.erase(it++);
		}
		else
		{
			(*it).Update();
			it++;
		}
	}

	if (time.asMilliseconds() > 4000)
	{
		_asteroids.clear();
		_asteroids.push_back(Asteroid());
		clock.restart();

	}
	


	std::list<Asteroid>::iterator it2 = _asteroids.begin();
	/*while (it2 != _asteroids.end())
	{
		if ((*it).Location().x + 6 < 0 ||
			(*it).Location().x - 6 > WNDWIDTH ||
			(*it).Location().y + 6 < 0 ||
			(*it).Location().y - 6 > WNDHEIGHT)
		{
			_bullets.erase(it++);
		}
		else
		{
			(*it).Update();
			it++;
		}
	}*/





}
void Game::Render()
{
	_window.clear(sf::Color::Black);
	_window.draw(_ship.Ship());
	for (auto& bullet : _bullets)
		_window.draw(bullet.Shape());

	for (auto& asteroid : _asteroids)
		_window.draw(asteroid.Shape());

	_window.display();
}