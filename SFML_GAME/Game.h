#pragma once

#include "Player.h"
#include<map>
#include"Bullet.h"
class Game
{
private:
	sf::RenderWindow* window;

	std::map<std::string, sf::Texture*> textures;
	std::vector<Bullet*> bullets;

	Player* player;


	void initWindow();
	void initTextures();
	void initPlayer();

public:
	Game();
	virtual ~Game();
	void run();

	void updatePollEvents();
	void updateInput();
	void updateBullets();
	void update();
	void render();
};

