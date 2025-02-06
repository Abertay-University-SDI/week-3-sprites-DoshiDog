#pragma once
#include "Framework/GameObject.h"

class Player : public GameObject
{
    sf::Texture texture;
    sf::Vector2f move_vector_;
    float move_speed_;
    
public:
    Player(sf::RenderWindow* hwnd);
    void handleInput(float dt) override;
    void setInput(Input* in);
    void update(float dt) override;
    static bool is_in_bounds_1_axis(float shape_position, float shape_size, float window_max, float shape_displacement);
};
