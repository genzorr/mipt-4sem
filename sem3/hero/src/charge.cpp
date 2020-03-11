#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

#include "charge.h"


Charge::Charge(float r, sf::Vector2f dir, sf::Vector2f position)
{
	charge = sf::CircleShape(r);
	charge.setPosition(position);

	charge.setFillColor(sf::Color::Red);

	float len = sqrtf(dir.x*dir.x + dir.y*dir.y);
	direction = sf::Vector2f(dir.x / len, dir.y / len);

	charge.setOrigin(r, r);
}


void Charge::updatePosition(float dt)
{
	charge.move(sf::Vector2f(direction.x*VELO*dt, direction.y*VELO*dt));
}
