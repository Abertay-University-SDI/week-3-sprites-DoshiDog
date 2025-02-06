#include "Level.h"
#include "Player.h"
Level::Level(sf::RenderWindow* hwnd, Input* in): playerObject(hwnd)
{
	window = hwnd;
	input = in;
	
	// initialise game objects
	texture.loadFromFile("gfx/Mushroom.png");
	backgroundTexture.loadFromFile("gfx/Level1_1.png");
	enemyOneTexture.loadFromFile("gfx/Goomba.png");
	enemyTwoTexture.loadFromFile("gfx/StarMushroom.png");
	cursorTexture.loadFromFile("gfx/icon.png");
	
	testSprite.setTexture(&texture);
	testSprite.setSize(sf::Vector2f(100, 100));
	testSprite.setPosition(100, 100);
	playerObject.setInput(input);
	enemyObject_1 = new Enemy(window, &enemyOneTexture, sf::Vector2f(100, 200));
	enemyObject_2 = new Enemy(window, &enemyTwoTexture, sf::Vector2f(100, 300));
	background = new Background(hwnd,&backgroundTexture , sf::Vector2f(11038 , 675));
	cursor = new Cursor(hwnd, input, &cursorTexture, sf::Vector2f(100, 100));
	window->setMouseCursorVisible(false);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	playerObject.handleInput(dt);
	sf::View view = window->getView();
	
	// Close window on Escape pressed.
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}
	if (input->isKeyDown(sf::Keyboard::A))
	{
		view.move(-100 * dt, 0);
	}
	if (input->isKeyDown(sf::Keyboard::D))
	{
		view.move(100 * dt, 0);
	}
	window->setView(view);
}

// Update game objects
void Level::update(float dt)
{
	playerObject.update(dt);
	enemyObject_1->update(dt);
	enemyObject_2->update(dt);
	cursor->update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	
	window->draw(*background);
	window->draw(testSprite);
	window->draw(playerObject);
	window->draw(*enemyObject_1);
	window->draw(*enemyObject_2);
	window->draw(*cursor);
	endDraw();
}
