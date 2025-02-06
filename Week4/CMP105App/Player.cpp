#include "Player.h"
using namespace sf;
Player::Player(RenderWindow* hwnd)
{
	window = hwnd;
	texture.loadFromFile("gfx/Mushroom.png");

	this->setTexture(&texture);
	this->setSize(Vector2f(100, 100));
	this->setPosition(200, 100);
	move_speed_ = 800;
}

void Player::setInput(Input* in)
{	
	input = in;
}

void Player::update(float dt)
{
	GameObject::update(dt);
	this->move(move_vector_*dt);
}



void Player::handleInput(float deltaTime)
{
    GameObject::handleInput(deltaTime);
	if (input->isKeyDown(Keyboard::Up) || input->isKeyDown(Keyboard::Down))
	{
		move_vector_.y = input->isKeyDown(Keyboard::Up) ? -move_speed_ : move_speed_; // apply y movement 
		if (!is_in_bounds_1_axis(this->getPosition().y,this->getLocalBounds().height, window->getSize().y, move_vector_.y*deltaTime)) // check if shape is in window bounds
		{ move_vector_.y = 0; }
	} else { move_vector_.y = 0; }

	// x axis movement
	if (input->isKeyDown(Keyboard::Left) || input->isKeyDown(Keyboard::Right))
	{
		move_vector_.x = input->isKeyDown(Keyboard::Left) ? -move_speed_ : move_speed_; // apply x movement 
		if (!is_in_bounds_1_axis(this->getPosition().x,this->getLocalBounds().width, window->getSize().x, move_vector_.x*deltaTime)) // check if shape is in window bounds
		{ move_vector_.x = 0; }
	} else { move_vector_.x = 0; }
}



// boundary check along one axis 
bool Player::is_in_bounds_1_axis(const float shape_position, const float shape_size, const float window_max, const float shape_displacement)
{
	if (shape_position + shape_displacement < 0 || shape_position + shape_displacement > window_max - shape_size){
		return false;
	} return true;
}
