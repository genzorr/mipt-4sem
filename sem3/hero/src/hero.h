/*
 * hero.h
 *
 *  Created on: Feb 28, 2020
 *      Author: michael
 */

#ifndef HERO_H_
#define HERO_H_

#define X 1920
#define Y 1080

#include <cmath>
#include "charge.h"

class Hero
{
public:
	sf::Sprite sprite;
	float x_size;
	float y_size;

	Hero();
	Hero(sf::Texture&, sf::Vector2f);

	sf::Vector2f toMouse(sf::RenderWindow& window);

	void moveHero(float, float);
	void rotateHero(sf::RenderWindow& window);
	void shootLaser(sf::RenderWindow& window);
	void shootParticle(sf::RenderWindow& window, std::vector<Charge>& charges);
};

class sfLine : public sf::Drawable
{
public:
    sfLine(const sf::Vector2f& point1, const sf::Vector2f& point2):
        color(sf::Color::Red), thickness(5.f)
    {
        sf::Vector2f direction = point2 - point1;

        float len = sqrt(direction.x*direction.x+direction.y*direction.y);
        sf::Vector2f unitDirection = sf::Vector2f(direction.x / len, direction.y / len);
        sf::Vector2f unitPerpendicular(-unitDirection.y,unitDirection.x);

        sf::Vector2f offset = (thickness/2.f)*unitPerpendicular;

        vertices[0].position = point1 + offset;
        vertices[1].position = point2 + offset;
        vertices[2].position = point2 - offset;
        vertices[3].position = point1 - offset;

        for (int i=0; i<4; ++i)
            vertices[i].color = color;
    }

    void draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        target.draw(vertices,4,sf::Quads);
    }


private:
    sf::Vertex vertices[4];
    float thickness;
    sf::Color color;
};


#endif /* HERO_H_ */
