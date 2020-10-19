#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Player.h"
class Game
{
public:
	sf::RenderWindow* window;

	Player* player;


	void initWindow();
	void initPlayer();
public:
	Game();
	virtual ~Game();
	void run();
	void update();
	void render();
};

