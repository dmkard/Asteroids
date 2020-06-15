#pragma once
#include "SFML/Graphics.hpp"
#include <string>
class Interface :
            public sf::Drawable
{
public:
    Interface();
    void Update(int score);

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    sf::Text _scoreLabel;
    sf::Text _score;
    sf::Font _font;

};

