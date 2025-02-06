#pragma once
#include "Framework/GameObject.h"

class Enemy : public GameObject
{
    float speed_;
public:
    Enemy(sf::RenderWindow* hwnd, const sf::Texture* texture, sf::Vector2f position);
    void update(float dt) override;
    static bool is_in_bounds_1_axis(float shape_position, float shape_size, float window_max, float shape_displacement);
};
