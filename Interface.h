#pragma once
#include "SFML/Graphics.hpp"
#include <string>
class Interface :
            public sf::Drawable
{
public:
    Interface();
    void Update();

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    sf::Text scoreLabel;
    sf::Text score;
    sf::Font font;

};

