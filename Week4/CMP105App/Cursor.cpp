#include "Cursor.h"

Cursor::Cursor(sf::RenderWindow* hwnd, Input* in, const sf::Texture* texture, sf::Vector2f size)
{
    window = hwnd;
    input = in;
    this->setTexture(texture);
    this->setSize(size);
}

void Cursor::update(float dt)
{
    GameObject::update(dt);
    this->setPosition(input->getMouseX(), input->getMouseY());
}
