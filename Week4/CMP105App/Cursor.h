#pragma once
#include "Framework/GameObject.h"

class Cursor : public GameObject
{
public:
    Cursor(sf::RenderWindow* hwnd,Input* in, const sf::Texture* texture, sf::Vector2f size);
    void update(float dt) override;
};
