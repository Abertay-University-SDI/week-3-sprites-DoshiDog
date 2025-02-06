#pragma once
#include "Framework/GameObject.h"
class Background : public GameObject
{
public:
    Background(sf::RenderWindow* hwnd, const sf::Texture* texture, sf::Vector2f size);
    
};
