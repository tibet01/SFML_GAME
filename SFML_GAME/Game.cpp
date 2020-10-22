#include "Game.h"
void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Swaglords of Space - Game 3", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}
void Game::initTextures()
{
	this->textures["BULLET"] = new sf::Texture();
	this->textures["BULLET"]->loadFromFile("bullet4.png");
}
void Game::initPlayer()
{
	this->player = new Player();
}

void Game::initEnemies()
{
	this->spawnTimerMax = 50.f;
	this->spawnTimer = this->spawnTimerMax;
}

Game::Game()
{
	this->initWindow();
	this->initTextures();
	this->initPlayer();
	this->initEnemies();
}
Game::~Game()
{
	delete this->window;
	delete this->player;


	for (auto &i : this->textures)
	{
		delete i.second;
	}

	for (auto *i:this->bullets)
	{
		delete i;
	}

	for (auto* i : this->enemies)
	{
		delete i;
	}
}
void Game::run()
{
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}


}
void Game::updatePollEvents()
{
	sf::Event e;
	while (this->window->pollEvent(e))
	{
		if (e.Event::type == sf::Event::Closed)
			this->window->close();
		if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
			this->window->close();
	}
}
void Game::updateInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->player->move(-1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->player->move(1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->player->move(0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->player->move(0.f, 1.f);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player->canAttack())
	{
		this->bullets.push_back(new Bullet(this->textures["BULLET"],
			this->player->getPos().x+this->player->getBounds().width*10/22.f, 
			this->player->getPos().y-this->player->getBounds().height/2.f,
			0.f,-1.f,5.f));
	}
}
void Game::updateBullets()
{
	unsigned counter = 0;
	for (auto* bullet : this->bullets)
	{
		bullet->update();

		if (bullet->getBounds().top + bullet->getBounds().height<0.f)
		{
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			--counter;

			//std::cout << this->bullets.size() << "\n";
		}
		++counter;
	}
}

void Game::updateEnemies()
{
	this->spawnTimer += 0.5f;
	if (this->spawnTimer >= this->spawnTimerMax)
	{
		this->enemies.push_back(new Enemy(rand() % 200, rand() % 200));
		this->spawnTimer = 0.f;
	}
	for (auto* enemy : this->enemies)
	{
		enemy->update();
	}
		
}

void Game::update()
{
	this->updatePollEvents();

	this->updateInput();

	this->player->update();

	this->updateBullets();

	this->updateEnemies();
}
void Game::render()
{
	this->window->clear();

	this->player->render(*this->window);

	for (auto *bullet:this->bullets )
	{
		bullet->render(this->window);
	}
	for (auto* enemy : this->enemies)
	{
		enemy->render(this->window);
	}

	this->window->display();
}
