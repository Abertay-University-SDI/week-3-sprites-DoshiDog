#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/BaseLevel.h"
#include "Framework/Input.h"
#include "Framework/GameObject.h"
#include <string.h>
#include <iostream>

#include "Background.h"
#include "Cursor.h"
#include "Enemy.h"
#include "Player.h"


class Level : BaseLevel {
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt) override;
	void update(float dt) override;
	void render() override;

private:
	// Level objects
	GameObject testSprite;
	Player playerObject	;
	Enemy* enemyObject_1;
	Enemy* enemyObject_2;
	Background* background;
	sf::Texture backgroundTexture;
	sf::Texture texture;
	sf::Texture enemyOneTexture;
	sf::Texture enemyTwoTexture;
	Cursor* cursor;
	sf::Texture cursorTexture;

};
