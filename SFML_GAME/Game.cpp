#include "Game.h"
void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Swaglords of Space - Game 3", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}
void Game::initPlayer()
{
	this->player = new Player();
}
Game::Game()
{
	this->initWindow();
	this->initPlayer();
}
Game::~Game()
{
	delete this->window;
	delete this->player;
}
void Game::run()
{
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}


}
void Game::update()
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
void Game::render()
{
	this->window->clear();

	this->player->render(*this->window);

	this->window->display();
}