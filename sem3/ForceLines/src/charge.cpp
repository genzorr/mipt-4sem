#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

#include "vector2.h"
#include "charge.h"

#define STEP 5
#define LINES_N	25
#define RADIUS	20


Charge::Charge(sf::Vector2i position, sf::Color color_, int sign_)
{
	lines_number = LINES_N;
	sign = sign_;
	color = color_;

	charge = sf::CircleShape(RADIUS);
	charge.setPosition(sf::Vector2f(position.x, position.y));
	charge.setFillColor(color);
	charge.setOrigin(RADIUS, RADIUS);

	float angle = 2*M_PI / (float)lines_number;
	for (int i = 0; i < lines_number; i++)
	{
		Vector2 v(-1, 0);
		v.rotate(angle*i);
		vectors.push_back(v);

		sf::VertexArray l(sf::LineStrip);
		lines_vertex.push_back(l);
	}
}


void Plot(sf::RenderWindow& window, std::vector<Charge>& charges)
{
	for (auto& charge: charges)
	{
		for (auto& l: charge.lines_vertex)
			window.draw(l);
	}

	for (auto& charge: charges)
		window.draw(charge.charge);
}

//bool isThat(sf::CircleShape& s1, sf::CircleShape& s2)
//{
//	sf::Vector2f
//	if (.x)
//}

bool CheckPointInside(std::vector<Charge>& charges, sf::CircleShape& charge, float x, float y)
{
	sf::Vector2f n = charge.getPosition();
	for (auto& c: charges)
	{
		sf::Vector2f f = c.charge.getPosition();
		if ((f.x == n.x) and (f.y == n.y))
			continue;

		sf::Vector2f v = f - sf::Vector2f(x, y);
		if ((v.x*v.x + v.y*v.y) <= RADIUS*RADIUS)
			return true;
	}

	return false;
}


void Charge::CountField(sf::RenderWindow& window, std::vector<Charge>& charges)
{
	for (int i = 0; i < lines_number; i++)
	{
		lines_vertex[i].clear();

		float x = charge.getPosition().x + vectors[i].x;
		float y = charge.getPosition().y + vectors[i].y;
		lines_vertex[i].append(sf::Vertex(sf::Vector2f(x, y), color));

		while ((x > (0-offset)) and (x < (window.getSize().x+offset)) and (y > (0-offset)) and (y < (window.getSize().y+offset)))
		{
			Vector2 resulted(0, 0);
			for (auto& c: charges)
			{
				Vector2 v(x - c.charge.getPosition().x, y - c.charge.getPosition().y);
				v = v / v.squareLen();
				resulted += v*c.sign;
			}
			resulted = resulted.norm();
			x += STEP*resulted.x*sign;
			y += STEP*resulted.y*sign;

			lines_vertex[i].append(sf::Vertex(sf::Vector2f(x, y), color));
			if (CheckPointInside(charges, charge, x, y))
				break;
		}
	}
}


void CreateUpdateFields(sf::RenderWindow& window, std::vector<Charge>& charges, int sign)
{
	window.clear(sf::Color::White);

	sf::Color color = (sign == 1) ? sf::Color::Red : sf::Color::Blue;
	Charge charge(sf::Mouse::getPosition(window), color, sign);
	charges.push_back(charge);

	for (auto& c: charges)
		c.CountField(window, charges);

	Plot(window, charges);
}
