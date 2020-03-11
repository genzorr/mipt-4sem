#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

#include "hero.h"
#include "charge.h"

Hero::Hero(sf::Texture& texture, sf::Vector2f vector)
{
	sprite = sf::Sprite(texture);

	sf::Vector2u spriteSize = sprite.getTexture()->getSize();

	sprite.setOrigin(spriteSize.x / 2, spriteSize.y / 2);
	sprite.scale(0.5f, 0.5f);

	x_size = spriteSize.x * sprite.getScale().x / 2;
	y_size = spriteSize.y * sprite.getScale().y / 2;

	sprite.setPosition(vector);
}

sf::Vector2f Hero::toMouse(sf::RenderWindow& window)
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	sf::Vector2f center = sprite.getPosition();
	return sf::Vector2f(mousePosition.x, mousePosition.y) - center;
}

void Hero::moveHero(float speed, float dt = 1.0f)
{
	sf::Vector2f v;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		v = sf::Vector2f(-speed*dt, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		v = sf::Vector2f(0, -speed*dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		v = sf::Vector2f(0, speed*dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		v = sf::Vector2f(speed*dt, 0);

	sprite.move(v);

	float x = sprite.getPosition().x, y = sprite.getPosition().y;
	if (x < x_size)
		sprite.setPosition(sf::Vector2f(x_size, y));
	else if (x > X - x_size)
		sprite.setPosition(sf::Vector2f(X - x_size, y));

	if (y < y_size)
			sprite.setPosition(sf::Vector2f(x, y_size));
	else if (y > Y - y_size)
		sprite.setPosition(sf::Vector2f(x, Y - y_size));
}

void Hero::rotateHero(sf::RenderWindow& window)
{
	sf::Vector2f d = this->toMouse(window);
	sprite.setRotation(90.0 + atan2f(d.y, d.x) * 180 / M_PI);
}


void Hero::shootLaser(sf::RenderWindow& window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		sf::Vector2f d = this->toMouse(window);
		sf::Vector2f center = sprite.getPosition();

		sfLine line = sfLine(center, sf::Vector2f(d.x*10, d.y*10));
		line.draw(window, sf::RenderStates::Default);
	}
}


void Hero::shootParticle(sf::RenderWindow& window, std::vector<Charge>& charges)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		Charge charge = Charge(10, this->toMouse(window), sprite.getPosition());
		charges.push_back(charge);
	}
}
