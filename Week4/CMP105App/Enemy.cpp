#include "Enemy.h"

Enemy::Enemy(sf::RenderWindow* hwnd, const sf::Texture* texture, const sf::Vector2f position)
{
    window = hwnd;
    this->setTexture(texture);
    this->setSize(sf::Vector2f(100, 100));
    this->setPosition(position);
    speed_ = 100;
}

void Enemy::update(float dt)
{
    GameObject::update(dt);
    if(!is_in_bounds_1_axis(this->getPosition().x,this->getLocalBounds().width, window->getSize().x,speed_*dt))
    {
        speed_ = (speed_ > 0) ? -speed_ : abs(speed_); // invert movement
    }
    this->move(speed_*dt, 0);
}

// boundary check along one axis 
bool Enemy::is_in_bounds_1_axis(const float shape_position, const float shape_size, const float window_max, const float shape_displacement)
{
    if (shape_position + shape_displacement < 0 || shape_position + shape_displacement > window_max - shape_size){
        return false;
    } return true;
}
