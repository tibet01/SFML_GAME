#include "Player.h"
void Player::initTexture()
{
	if (!this->texture.loadFromFile("ship.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	}
}
void Player::initSprite()
{
	this->sprite.setTexture(this->texture);
}
Player::Player()
{
	this->initTexture();
	this->initSprite();
}
Player::~Player()
{

}
void Player::update()
{

}
void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}