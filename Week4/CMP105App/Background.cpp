#include "Background.h"

Background::Background(sf::RenderWindow* hwnd, const sf::Texture* texture, sf::Vector2f size)
{
    window = hwnd;
    this->setTexture(texture);
    this->setSize(size);
}
