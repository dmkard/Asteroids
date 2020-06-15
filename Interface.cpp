#include "Interface.h"
#include <iostream>

Interface::Interface()
{
	_scoreLabel.setString("Score: ");
	if (!_font.loadFromFile("robot.ttf"))
		std::cout << "Something wrong, I feel it\n";
	_scoreLabel.setFont(_font);
	_scoreLabel.setCharacterSize(30); // in pixels, not points
	_scoreLabel.setFillColor(sf::Color::White);
	_scoreLabel.setPosition(10., 10.);

	_score.setFont(_font);
	_score.setCharacterSize(30); // in pixels, not points
	_score.setFillColor(sf::Color::White);
	_score.setPosition(120., 10.);
}

void Interface::Update(int score)
{
	_score.setString(std::to_string(score));
}

void Interface::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_scoreLabel);
	target.draw(_score);
}
