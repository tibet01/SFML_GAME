#pragma once

#include "Player.h"
#include<map>
#include"Bullet.h"
#include "Enemy.h"
class Game
{
private:
	sf::RenderWindow* window;

	std::map<std::string, sf::Texture*> textures;
	std::vector<Bullet*> bullets;

	Player* player;

	float spawnTimer;
	float spawnTimerMax;
	std::vector<Enemy*> enemies;



	void initWindow();
	void initTextures();

	void initPlayer();
	void initEnemies();

public:
	Game();
	virtual ~Game();
	void run();

	void updatePollEvents();
	void updateInput();
	void updateBullets();
	void updateEnemies();
	void update();
	void render();
};

