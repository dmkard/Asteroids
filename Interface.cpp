#include "Interface.h"
#include <iostream>

Interface::Interface()
{
	scoreLabel.setString("Score: ");
	if (!font.loadFromFile("robot.ttf"))
		std::cout << "Something wrong, I feel it\n";
	scoreLabel.setFont(font);
	scoreLabel.setCharacterSize(30); // in pixels, not points
	scoreLabel.setFillColor(sf::Color::White);
	scoreLabel.setPosition(10., 10.);

	score.setFont(font);
	score.setCharacterSize(30); // in pixels, not points
	score.setFillColor(sf::Color::White);
	score.setPosition(120., 10.);
}

void Interface::Update()
{
	score.setString("69");
}

void Interface::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(scoreLabel);
	target.draw(score);
}
